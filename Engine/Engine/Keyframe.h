#pragma once
#include "ExternalInclude.h"


class Keyframe
{
public:
	Keyframe(unsigned int timeStamp);
	~Keyframe();

	void addAction(string name, function<void(string)> action);
	void activateKeyframe();
	unsigned int getTimeStamp();

private:
	vector<function<void(string)>> actions;
	vector<string> names;
	unsigned int timeStamp;
};



