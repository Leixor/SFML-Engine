#include "Animation.h"

Animation::Animation(unsigned int updateRate)
{
	this->updateCount = 1;
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

	if (this->keyframeHandler.exists(currentTime))
		this->keyframeHandler.activateKeyframe(currentTime);

	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->isRunning())
		{
			this->subAnimations.atIndex(i)->update(&this->objects);
		}
	}

	this->increaseTimeCount();

	//schaut ob die animation fertig ist
	if (this->keyframeHandler.behindLastKeyframe(this->getTime()))
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