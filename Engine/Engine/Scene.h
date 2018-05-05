#pragma once
#include "EventHandler.h"
#include "GlobalEnums.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update();
	void updateSync();

	EventHandler sceneEvents;
	Visibility sceneVisibility;
protected:
	// Time in milliseconds till update
	unsigned int updateRate;
private:
	// Counter for updateRate
	unsigned int updateCount;
};

