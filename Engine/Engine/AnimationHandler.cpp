#include "AnimationHandler.h"

AnimationHandler::AnimationHandler()
{
}

AnimationHandler::~AnimationHandler()
{
}

void AnimationHandler::update()
{
	for (unsigned int i = 0; i < this->animations.size(); i++)
	{
		if (this->animations.atIndex(i)->isRunning())
			this->animations.atIndex(i)->update();
	}
}

void AnimationHandler::run(string name, bool loop)
{
	this->animations.at(name)->start(loop);
}

void AnimationHandler::restart(string name)
{
	this->animations.at(name)->restart();
}

void AnimationHandler::resume(string name)
{
	this->animations.at(name)->resume();
}

void AnimationHandler::pause(string name)
{
	this->animations.at(name)->pause();
}

Animation* AnimationHandler::addAnimation(string name, Animation* animation)
{
	this->animations.push(name, animation);
	return this->animations.at(name);
}

void AnimationHandler::removeAnimation(string name)
{
	this->animations.removeAt(name);
}

