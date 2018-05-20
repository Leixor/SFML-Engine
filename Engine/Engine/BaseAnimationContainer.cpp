#include "BaseAnimationContainer.h"

BaseAnimationContainer::BaseAnimationContainer()
{
}

BaseAnimationContainer::~BaseAnimationContainer()
{
}

bool BaseAnimationContainer::update(vector<AnimationObject*>* objects)
{
	unsigned int currentTime = this->getTime();

	if (this->keyframeExists(currentTime))
		this->activateKeyframe(currentTime);

	this->running = false;
	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->update(objects))
		{
			this->running = true;;
		}
	}
	//Asdaiwhdoiasodasdas
	

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
