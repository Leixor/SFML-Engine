#include "BaseAnimationContainer.h"

BaseAnimationContainer::BaseAnimationContainer()
{
}

BaseAnimationContainer::~BaseAnimationContainer()
{
}

bool BaseAnimationContainer::update(vector<AnimationObject*>* objects)
{
	if (!this->running)
		return this->running;

	unsigned int currentTime = this->getTime();

	if (this->keyframeExists(currentTime))
		this->activateKeyframe(currentTime);

	this->running = false;
	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->update(objects))
		{
			this->running = true;
		}
	}

	// schaut ob die animation fertig ist
	if (this->behindLastKeyframe(this->getTime()) && !this->running && this->isLooping())
	{
		this->start(true);
	}

	this->increaseTimeCount();

	return this->running;
}

void BaseAnimationContainer::setUpdateRate(unsigned int updateRate)
{
	this->updateRate = updateRate;
	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		this->subAnimations.atIndex(i)->setUpdateRate(updateRate);
	}
}

BaseAnimation* const BaseAnimationContainer::getSubAnimation(string name)
{
	return this->subAnimations.at(name);
}
