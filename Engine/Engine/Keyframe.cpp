#include "Keyframe.h"

Keyframe::Keyframe(unsigned int timeStamp)
{
	this->timeStamp = timeStamp;
}

Keyframe::~Keyframe()
{
}

void Keyframe::addAction(string name, function<void(string)> action)
{
	this->actions.push_back(action);
	this->names.push_back(name);
}

void Keyframe::activateKeyframe()
{
	for (unsigned int i = 0; i < this->actions.size(); i++)
		this->actions.at(i)(this->names.at(i));
}

unsigned int Keyframe::getTimeStamp()
{
	return this->timeStamp;
}

