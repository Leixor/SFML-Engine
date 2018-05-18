#pragma once
#include "Keyframe.h"

class KeyframeHandler
{
public:
	KeyframeHandler();
	~KeyframeHandler();

	void addKeyframe(unsigned int time, function<void(void)> action, string name = "");
	void removeKeyframe(unsigned int time);
	void removeKeyframeAction(unsigned int time, string actionName);
	void activateKeyframe(unsigned int time);

	bool exists(unsigned int time);
	bool behindLastKeyframe(unsigned int time);
private:
	map<unsigned int, Keyframe*> keyframes;
	unsigned int lastTimeStamp;
};

