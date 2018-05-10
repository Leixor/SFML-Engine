#pragma once
#include "ExternalInclude.h"
#include "SortableMap.h"
#include "PhysicalBaseObject.h"
#include "BaseObject.h"
#include "SceneHandler.h"

class PhysicalWorld 
{
public:
	PhysicalWorld(Scene* scene);
	~PhysicalWorld();

	PhysicalBaseObject* addPhysicalObject(string baseObjectName, PhysicalBaseObject* object);

	virtual void updatePhysicalWorld();
	virtual void updateObjects();

	virtual void setupWorld();

	// Set update rate in milliseconds
	void setUpdateRate(unsigned int updateRate);
private:
	unsigned int updateRate;
	SortableMap<string, PhysicalBaseObject*> objects;
	Scene* scene;

};

