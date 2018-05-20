#include "Animation.h"

Animation::Animation(unsigned int updateRate)
{
	this->updateRate = updateRate;
	this->updateCount = updateRate / MS_PER_UPDATE;
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

bool Animation::update(vector<AnimationObject*>* objects)
{
	counter++;
	unsigned int currentTime = this->getTime();

	if (this->keyframeExists(currentTime))
		this->activateKeyframe(currentTime);

	this->running = false;
	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->update(&this->objects))
		{
			this->running = true;
		}
	}

	//schaut ob die animation fertig ist
	if (this->behindLastKeyframe(this->getTime()) && !this->running)
	{
			if (this->isLooping())
				this->start(true);
			else
				this->running = false;
	}

	this->increaseTimeCount();

	return this->running;
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