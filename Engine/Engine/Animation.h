#pragma once
#include "SubAnimation.h"
#include "Keyframe.h"
#include "BaseObject.h"
#include "UnorderedMap.h"

enum KeyframeAction
{
	ANISTART = 1,
	ANIRESUME = 2,
	ANIPAUSE = 4,
	ANIRESTART = 8
};

class Animation : public SubAnimation
{
public:
	Animation(unsigned int updateRate = 20);
	~Animation() {}

	void update();
	void update(BaseObject* object);

	template <typename returnType>
	returnType addSubAnimation(string name, returnType animation, unsigned int time = 0);
	void addSubAnimation(string name, SubAnimation* animation, unsigned int time = 0);
	void addKeyframe(string name, KeyframeAction action, unsigned int time);
	void removeKeyframe(unsigned int time);
	void addObject(BaseObject* object);
	void removeObject(BaseObject* object);
private:
	vector<Keyframe*> Keyframes;
	vector<BaseObject*> objects;
	UnorderedMap<string, SubAnimation*> subAnimations;
	unsigned int updateRateCount;
};

template<typename returnType>
inline returnType Animation::addSubAnimation(string name, returnType animation, unsigned int time)
{
	animation->setUpdateRate(this->updateRate);
	this->subAnimations.push(name, animation);
	this->addKeyframe(name, ANISTART, time);
	return animation;
}
