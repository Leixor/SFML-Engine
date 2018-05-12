#include "BaseAnimation.h"

BaseAnimation::BaseAnimation()
{
	this->timeCount = 0;
	this->running = false;
}

BaseAnimation::~BaseAnimation()
{
}

void BaseAnimation::start(bool loop)
{
	if (!this->running)
	{
		this->running = true;
		this->loop = loop;
		this->timeCount = 0;
	}
}

void BaseAnimation::restart()
{
	this->timeCount = 0;
	this->running = true;
}

void BaseAnimation::pause()
{
	if (this->running)
		this->running = false;
}

void BaseAnimation::resume()
{
	if (!this->running)
		this->running = true;
}

void BaseAnimation::setLooping(bool loop)
{
	this->loop = loop;
}

bool BaseAnimation::isRunning()
{
	return this->running;
}

void BaseAnimation::increaseTimeCount()
{
	this->timeCount++;
}

void BaseAnimation::setUpdateRate(unsigned int updateRate)
{
	this->updateRate = updateRate;
}

unsigned int BaseAnimation::getTime()
{
	return this->timeCount * this->updateRate;
}

bool BaseAnimation::isLooping()
{
	return this->loop;
}
