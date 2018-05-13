#pragma once
#include "SubAnimation.h"
#include "KeyframeHandler.h"
#include "Keyframe.h"
#include "SortableMap.h"



class Animation : public BaseAnimation
{
public:
	Animation(unsigned int updateRate = MS_PER_UPDATE);
	~Animation() {}

	void updateSync();
	void update(vector<AnimationObject*>* objects);

	// Subanimationhandling
	template <typename returnType>
	returnType addSubAnimation(string name, returnType animation, unsigned int startTime = 0);

	// Keyframehandling
	void addKeyframe(string name, KeyframeAction action, unsigned int time);

	// Objecthandling
	void addObject(AnimationObject* object);
	void removeObject(AnimationObject* object);

	void setUpdateRate(unsigned int updateRate);
	KeyframeHandler keyframeHandler;
private:
	SortableMap<string, BaseAnimation*> subAnimations;
	vector<AnimationObject*> objects;
	unsigned int updateCount;
	unsigned int lastTimeStamp;
};

template<typename returnType>
inline returnType Animation::addSubAnimation(string name, returnType animation, unsigned int startTime)
{
	animation->setUpdateRate(this->updateRate);
	this->subAnimations.push(name, animation);
	this->addKeyframe(name, ANISTART, startTime);
	return animation;
}
