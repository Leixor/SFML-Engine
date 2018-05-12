#include "Animation.h"

Animation::Animation(unsigned int updateRate)
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

void Animation::update(AnimationObject * object)
{
	unsigned int currentTime = this->getTime();

	if (keyframes.itemExists(currentTime))
		this->keyframes.at(currentTime)->activateKeyframe();

	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->isRunning())
		{
			if (object == nullptr)
				for(unsigned int k = 0; k < this->objects.size(); k++)
					this->subAnimations.atIndex(i)->update(this->objects.at(k));
			else
				this->subAnimations.atIndex(i)->update(object);
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

Animation* Animation::addAnimation(string name, unsigned int time)
{
	Animation* animation = new Animation(this->updateRate);
	this->subAnimations.push(name, animation);
	this->addKeyframe(name, ANISTART, time);
	return animation;
}

void Animation::addKeyframe(string name, KeyframeAction action, unsigned int time)
{
	if (this->lastTimeStamp < time)
		this->lastTimeStamp = time;

	if (!this->keyframes.itemExists(time))
		this->keyframes.push(time, new Keyframe());

	Keyframe* frame = this->keyframes.at(time);

	switch (action)
	{
		case ANISTART:
			frame->addAction([&, name]() {this->subAnimations.at(name)->start(); });
			break;
		case ANIPAUSE:
			frame->addAction([&, name]() {this->subAnimations.at(name)->pause(); });
			break;
		case ANIRESTART:
			frame->addAction([&, name]() {this->subAnimations.at(name)->restart(); });
			break;
		case ANIRESUME:
			frame->addAction([&, name]() {this->subAnimations.at(name)->resume(); });
			break;
		case ANILOOPING:
			frame->addAction([&, name]() {this->subAnimations.at(name)->setLooping(); });
	}
}

void Animation::removeKeyframe(unsigned int time)
{
	if (this->lastTimeStamp == time)
	{
		unsigned int newLastTimeStamp = 0;
		for (unsigned int i = 0; i < this->keyframes.size(); i++)
		{
			unsigned int tmp = this->keyframes.findByIndex(i);
			if (newLastTimeStamp < tmp)
				newLastTimeStamp = tmp;
		}
		this->lastTimeStamp = newLastTimeStamp;
	}

	this->keyframes.removeAt(time);
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

