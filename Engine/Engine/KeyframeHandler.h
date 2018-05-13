#pragma once
#include "Keyframe.h"
#include "Animation.h"
#include "BaseAnimationContainer.h"


class KeyframeHandler
{
public:
	KeyframeHandler();
	~KeyframeHandler();
	void addKeyframe(string name, function<void(void)> action, unsigned int time);
	void removeKeyframe(unsigned int time);
	void removeKeyframeAction(unsigned int time, string actionName);
	void activateKeyframe(unsigned int time);
	bool exists(unsigned int time);

private:
	map<unsigned int, Keyframe*> keyframeHandler;
	unsigned int lastTimeStamp;
};

