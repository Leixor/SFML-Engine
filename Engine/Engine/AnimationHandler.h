#pragma once
#include "SortableMap.h"
#include "Animation.h"

class AnimationHandler
{
public:
	AnimationHandler();
	~AnimationHandler();

	bool update();
	void run(string name, bool loop = false);
	void restart(string name);
	void resume(string name);
	void pause(string name);

	Animation* addAnimation(string name, Animation* animation);
	void removeAnimation(string name);
private:
	SortableMap<string, Animation*> animations;
};



