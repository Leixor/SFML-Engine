#include "Keyframe.h"

Keyframe::Keyframe()
{
}

Keyframe::~Keyframe()
{
}

void Keyframe::addAction(function<void(void)> action)
{
	this->actions.push_back(action);
}

void Keyframe::activateKeyframe()
{
	for (unsigned int i = 0; i < this->actions.size(); i++)
		this->actions.at(i)();
}

