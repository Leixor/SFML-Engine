#include "BaseAnimationContainer.h"

BaseAnimationContainer::BaseAnimationContainer() : keyframeHandler()
{
}

BaseAnimationContainer::~BaseAnimationContainer()
{
}

void BaseAnimationContainer::update(vector<AnimationObject*>* objects)
{
	unsigned int currentTime = this->getTime();

	if (this->keyframeHandler.exists(currentTime))
		this->keyframeHandler.activateKeyframe(currentTime);

	for (unsigned int i = 0; i < this->subAnimations.size(); i++)
	{
		if (this->subAnimations.atIndex(i)->isRunning())
		{
			this->subAnimations.atIndex(i)->update(objects);
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

void BaseAnimationContainer::setUpdateRate(unsigned int updateRate)
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

SortableMap<string, BaseAnimation*>* const BaseAnimationContainer::getSubAnimations()
{
	return &this->subAnimations;
}
