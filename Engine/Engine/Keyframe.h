#pragma once
#include "ExternalInclude.h"


class Keyframe
{
public:
	Keyframe(unsigned int timeStamp);
	~Keyframe();

	void addAction(function<void(void)> action);
	void activateKeyframe();
	unsigned int getTimeStamp();

private:
	vector<function<void(void)>> actions;
	unsigned int timeStamp;
};



