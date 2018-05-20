#pragma once
#include "AnimationObject.h"
#include "ExternalInclude.h"

class BaseAnimation
{
public:
	BaseAnimation();
	~BaseAnimation();

	virtual bool update(vector<AnimationObject*>* objects) = 0;

	void start(bool loop = false);
	void restart();
	void pause();
	void resume();
	void setLooping(bool loop = true);

	bool isRunning();
	virtual void setUpdateRate(unsigned int updateRate) = 0;
protected:
	bool running;
	unsigned int updateRate;

	void increaseTimeCount();

	unsigned int getTime();
	bool isLooping();
	int counter;
private:
	unsigned int timeCount;
	bool loop;
	
};

