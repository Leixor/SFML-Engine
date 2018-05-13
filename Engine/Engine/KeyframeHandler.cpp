#include "KeyframeHandler.h"



KeyframeHandler::KeyframeHandler()
{
}


KeyframeHandler::~KeyframeHandler()
{
}

void KeyframeHandler::addKeyframe(string actionName, function<void(void)> action, unsigned int time)
{
	if (this->lastTimeStamp < time)
		this->lastTimeStamp = time;

	if (this->keyframeHandler.find(time) != this->keyframeHandler.end())
		this->keyframeHandler.emplace(time, new Keyframe());

	Keyframe* frame = this->keyframeHandler.at(time);

	frame->addAction(action, actionName);
}

void KeyframeHandler::removeKeyframe(unsigned int time)
{
	if (this->lastTimeStamp == time)
	{
		auto it = this->keyframeHandler.end();
		it--;
		this->lastTimeStamp = it->first;
	}
	this->keyframeHandler.erase(time);
}

void KeyframeHandler::removeKeyframeAction(unsigned int time, string actionName)
{
	this->keyframeHandler.at(time)->removeAction(actionName);
}

void KeyframeHandler::activateKeyframe(unsigned int time)
{
	this->keyframeHandler.at(time)->activateKeyframe();
}

bool KeyframeHandler::exists(unsigned int time)
{
	return this->keyframeHandler.find(time) != this->keyframeHandler.end();
}
