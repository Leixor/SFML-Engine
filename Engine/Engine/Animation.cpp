#include "Animation.h"

Animation::Animation(unsigned int updateRate) : keyframeHandler(), distinct(true)
{
	this->updateCount = 1;
	this->lastTimeStamp = 0;
	this->updateRate = updateRate;
}

void Animation::updateSync()
{
	if (updateCount >= updateRate / MS_PER_UPDATE)
	{
		this->update(nullptr);
		updateCount = 1;
	}
	else
	{
		updateCount++;
	}
}

void Animation::update(vector<AnimationObject*>* objects)
{
	unsigned int currentTime = this->getTime();

	if (keyframeHandler.exists(currentTime))
		keyframeHandler.activateKeyframe(currentTime);

	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->isRunning())
		{
			this->subAnimations.atIndex(i)->update(&this->objects);
		}
	}

	this->increaseTimeCount();

	//schaut ob die animation fertig ist
	if (this->getTime() > this->lastTimeStamp)
	{
		bool finished = true;
		for (unsigned int i = 0; i < this->subAnimations.size(); i++)
		{
			if (this->subAnimations.atIndex(i)->isRunning())
				finished = false;
		}
		if (finished)
		{
			if (this->isLooping())
				this->start(true);
			else
				this->running = false;
		}
	}
}



void Animation::addKeyframe(string name, KeyframeAction action, unsigned int time)
{
	switch (action)
	{
		case ANISTART:
			this->keyframeHandler.addKeyframe(name, [&, name]() {this->subAnimations.at(name)->start(); }, time);
			break;
		case ANIPAUSE:
			this->keyframeHandler.addKeyframe(name, [&, name]() {this->subAnimations.at(name)->pause(); }, time);
			break;
		case ANIRESTART:
			this->keyframeHandler.addKeyframe(name, [&, name]() {this->subAnimations.at(name)->restart(); }, time);
			break;
		case ANIRESUME:
			this->keyframeHandler.addKeyframe(name, [&, name]() {this->subAnimations.at(name)->resume(); }, time);
			break;
		case ANILOOPING:
			this->keyframeHandler.addKeyframe(name, [&, name]() {this->subAnimations.at(name)->setLooping(); }, time);
	}
}


void Animation::addObject(AnimationObject* object)
{
	this->objects.push_back(object);
}

void Animation::removeObject(AnimationObject* object)
{
	auto it = find(this->objects.begin(), this->objects.end(), object);

	if (it == this->objects.end())
		throw;

	this->objects.erase(it);	
}

void Animation::setUpdateRate(unsigned int updateRate)
{
	this->updateRate = updateRate;
	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		this->subAnimations.atIndex(i)->setUpdateRate(updateRate);

		SubAnimation* tmp = dynamic_cast<SubAnimation*>(this->subAnimations.atIndex(i));
		if (tmp != nullptr)
			tmp->setup();
	}
}

