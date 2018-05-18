#pragma once
#include "BaseAnimation.h"
#include "SubAnimation.h"
#include "KeyframeHandler.h"
#include "SortableMap.h"

class BaseAnimationContainer : public BaseAnimation
{
public:
	BaseAnimationContainer();
	~BaseAnimationContainer();

	void update(vector<AnimationObject*>* objects);
	void setUpdateRate(unsigned int updateRate);
	template <typename returnType>
	returnType addSubAnimation(string name, returnType animation, unsigned int startTime = 0);

	SortableMap<string, BaseAnimation*>* const getSubAnimations();

	KeyframeHandler keyframeHandler;
protected:
	SortableMap<string, BaseAnimation*> subAnimations;
};

template<typename returnType>
inline returnType BaseAnimationContainer::addSubAnimation(string name, returnType animation, unsigned int startTime)
{
	animation->setUpdateRate(this->updateRate);
	this->subAnimations.push(name, animation);
	this->keyframeHandler.addKeyframe(startTime, [&, name] { this->subAnimations.at(name)->start(); }, name);
	return animation;
}
