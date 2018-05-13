#pragma once
#include "ExternalInclude.h"


class Keyframe
{
public:
	Keyframe();
	~Keyframe();

	void addAction(function<void(void)> action);
	void activateKeyframe();
private:
	vector<function<void(void)>> actions;
};



