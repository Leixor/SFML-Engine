#pragma once
#include "SubAnimation.h"
#include "Keyframe.h"
#include "SortableMap.h"

enum KeyframeAction
{
	ANISTART = 1,
	ANIRESUME = 2,
	ANIPAUSE = 4,
	ANIRESTART = 8,
	ANILOOPING = 16
};

class Animation : public BaseAnimation
{
public:
	Animation(unsigned int updateRate = MS_PER_UPDATE);
	~Animation() {}

	void updateSync();
	void update(AnimationObject* object);

	// Subanimationhandling
	template <typename returnType>
	returnType addSubAnimation(string name, returnType animation, unsigned int time = 0);
	Animation* addAnimation(string name, bool distinct, unsigned int time = 0);

	// Keyframehandling
	void addKeyframe(string name, KeyframeAction action, unsigned int time);
	void removeKeyframe(unsigned int time);

	// Objecthandling
	void addObject(AnimationObject* object);
	void removeObject(AnimationObject* object);

	void setUpdateRate(unsigned int updateRate);
private:
	Animation(bool distinct, unsigned int updateRate);

	SortableMap<unsigned int, Keyframe*> keyframes;
	SortableMap<string, BaseAnimation*> subAnimations;
	vector<AnimationObject*> objects;
	bool distinct;
	unsigned int updateCount;
	unsigned int lastTimeStamp;
};

template<typename returnType>
inline returnType Animation::addSubAnimation(string name, returnType animation, unsigned int time)
{
	animation->setUpdateRate(this->updateRate);
	this->subAnimations.push(name, animation);
	this->addKeyframe(name, ANISTART, time);
	return animation;
}
