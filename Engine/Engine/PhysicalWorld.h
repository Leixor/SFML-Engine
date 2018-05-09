#pragma once
#include "ExternalInclude.h"
#include "UnorderedMap.h"
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

	// Set update rate in milliseconds
	void setUpdateRate(unsigned int updateRate);
private:
	unsigned int updateRate;
	UnorderedMap<string, PhysicalBaseObject*> objects;
	Scene* scene;

};

