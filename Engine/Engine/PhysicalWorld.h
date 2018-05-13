#pragma once
#include "ExternalInclude.h"
#include "SortableMap.h"
#include "SceneHandler.h"
#include PHYSICAL_OBJECT_INCLUDE
#include PHYSICAL_WORLD_INCLUDE

class PhysicalWorld  : public PHYSICAL_WORLD_CLASS
{
public:
	PhysicalWorld(Scene* scene);
	~PhysicalWorld();

	virtual void setupWorld() = 0;
	virtual void updatePhysicalWorld() = 0;

	PHYSICAL_OBJECT* addPhysicalObject(string baseObjectName, PHYSICAL_OBJECT* object);

	
	virtual void updateObjects();

	

	// Set update rate in milliseconds
	void setUpdateRate(unsigned int updateRate);
private:
	unsigned int updateRate;
	SortableMap<BASE_OBJECT*, PHYSICAL_OBJECT*> objects;
	Scene* scene;

};

