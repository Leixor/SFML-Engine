#pragma once
#include "AnimationObject.h"

class BaseAnimation
{
public:
	BaseAnimation();
	~BaseAnimation();

	virtual void update(AnimationObject* object) = 0;

	void start(bool loop = false);
	void restart();
	void pause();
	void resume();
	void setLooping(bool loop = true);

	bool isRunning();
protected:
	bool running;
	unsigned int updateRate;

	void increaseTimeCount();
	void setUpdateRate(unsigned int updateRate);

	unsigned int getTime();
	bool isLooping();
private:
	unsigned int timeCount;
	bool loop;
};

