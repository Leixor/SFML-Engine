#include "Keyframe.h"

Keyframe::Keyframe()
{
}

Keyframe::~Keyframe()
{
}

void Keyframe::addAction(function<void(void)> action, string name)
{
	if (name == "")
		this->actions.emplace(to_string(this->actions.size()), action);
	else
		this->actions.emplace(name, action);
}

void Keyframe::removeAction(string name)
{
	this->actions.erase(name);
}

void Keyframe::activateKeyframe()
{
	for (auto it = actions.begin(); it != actions.end(); it++)
		this->actions.at(it->first)();
}

