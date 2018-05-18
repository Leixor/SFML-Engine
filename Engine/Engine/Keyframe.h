#pragma once
#include "ExternalInclude.h"

class Keyframe
{
public:
	Keyframe();
	~Keyframe();
	void activateKeyframe();
	void addAction(function<void(void)> action, string name = "");
	void removeAction(string name);
private:
	map<string, function<void(void)>> actions;
};