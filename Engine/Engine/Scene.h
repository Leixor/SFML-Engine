#pragma once
#include "EventHandler.h"
#include "GlobalEventHandler.h"
#include "BaseObject.h"
#include "GlobalEnums.h"
#include "Frameworks.h"

class Scene
{
public:
	Scene();
	~Scene();

	virtual void update();
	virtual void draw();
	virtual void handleEvents(LIBRARY_EVENT_CLASS eventType);
	virtual void handleInputs();

	void updateSync();

	EventHandler sceneEvents;
	Visibility sceneVisibility;
protected:
	// Time in milliseconds till update
	unsigned int updateRate;
	UnorderdMap<string, BaseObject*> objects;
private:
	// Counter for updateRate
	unsigned int updateCount;
};

