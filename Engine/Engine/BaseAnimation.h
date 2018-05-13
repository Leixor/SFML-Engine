#pragma once
#include "AnimationObject.h"

class BaseAnimation
{
public:
	BaseAnimation();
	~BaseAnimation();

	virtual void update(vector<AnimationObject*>* objects) = 0;

	void start(bool loop = false);
	void restart();
	void pause();
	void resume();
	void setLooping(bool loop = true);

	bool isRunning();
	virtual void setUpdateRate(unsigned int updateRate);
protected:
	bool running;
	unsigned int updateRate;

	void increaseTimeCount();

	unsigned int getTime();
	bool isLooping();
private:
	unsigned int timeCount;
	bool loop;
};

