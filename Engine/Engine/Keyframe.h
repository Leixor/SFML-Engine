#pragma once
#include "ExternalInclude.h"
enum KeyframeAction
{
	ANISTART = 1,
	ANIRESUME = 2,
	ANIPAUSE = 4,
	ANIRESTART = 8,
	ANILOOPING = 16
};


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



