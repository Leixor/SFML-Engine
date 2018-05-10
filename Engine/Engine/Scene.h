#pragma once
#include "EventHandler.h"
#include "GlobalEventHandler.h"
#include "GlobalEnums.h"
#include "EngineSetup.h"
#include "ConfigHandler.h"
#include BASE_OBJECT_INCLUDE

class Scene
{
public:
	Scene();
	~Scene();

	// Game loop functionality
	virtual void update();
	virtual void draw();
	virtual void handleEvents(EVENT_CLASS eventType);
	virtual void handleInputs();

	// Scene preparation and configuration
	virtual bool setupResources() = 0;
	virtual void confVarUpdate() = 0;

	void updateSync();

	// Helper Objects
	EventHandler sceneEvents;
	ConfigHandler* configHelper;
	Visibility visibility;

	template <typename returnType>
	returnType Scene::addObject(string name, returnType toAdd, int priority = -1);
	BASE_OBJECT* getObjectByName(string name);

protected:
	// Time in milliseconds till update
	unsigned int updateRate;
	SortableMap<string, BASE_OBJECT*> objects;
private:
	// Counter for updateRate
	unsigned int updateCount;
};

template<typename returnType>
inline returnType Scene::addObject(string name, returnType toAdd, int priority)
{
	this->objects.push(name, toAdd);

	if (priority != -1)
		this->setObjectPriority(name, priority);

	this->setObjectVisibility(name, toAdd->shapeVisible);

	return toAdd;
}
