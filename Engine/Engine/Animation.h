#pragma once
#include "BaseAnimationContainer.h"

class Animation : public BaseAnimationContainer
{
public:
	Animation(unsigned int updateRate = MS_PER_UPDATE);
	~Animation() {}

	void updateSync();
	bool update(vector<AnimationObject*>* objects);
	
	void addObject(AnimationObject* object);
	void removeObject(AnimationObject* object);
	void setUpdateRate(unsigned int updateRate);
protected:
	vector<AnimationObject*> objects;
	unsigned int updateCount;
};
