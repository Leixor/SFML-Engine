#include "KeyframeHandler.h"

KeyframeHandler::KeyframeHandler()
{
}

KeyframeHandler::~KeyframeHandler()
{
}

void KeyframeHandler::addKeyframe(unsigned int time, function<void(void)> action, string actionName)
{
	if (this->lastTimeStamp < time)
		this->lastTimeStamp = time;

	if (this->keyframes.find(time) == this->keyframes.end())
		this->keyframes.emplace(time, new Keyframe());

	Keyframe* frame = this->keyframes.at(time);
	frame->addAction(action, actionName);
}

void KeyframeHandler::removeKeyframe(unsigned int time)
{
	if (this->lastTimeStamp == time)
	{
		auto it = this->keyframes.end();
		it--;
		this->lastTimeStamp = it->first;
	}
	this->keyframes.erase(time);
}

void KeyframeHandler::removeKeyframeAction(unsigned int time, string actionName)
{
	this->keyframes.at(time)->removeAction(actionName);
}

void KeyframeHandler::activateKeyframe(unsigned int time)
{
	this->keyframes.at(time)->activateKeyframe();
}

bool KeyframeHandler::keyframeExists(unsigned int time)
{
	return this->keyframes.find(time) != this->keyframes.end();
}

bool KeyframeHandler::behindLastKeyframe(unsigned int time)
{
	return (time >= this->lastTimeStamp);
}
