#include "PhysicalWorld.h"


PhysicalWorld::PhysicalWorld(Scene * scene) : scene(scene)
{
}

PhysicalWorld::~PhysicalWorld()
{
}

PhysicalBaseObject* PhysicalWorld::addPhysicalObject(string baseObjectName, PHYSICAL_OBJECT* object)
{
	this->objects.push(scene->getObjectByName(baseObjectName), object);
	return object;
}


void PhysicalWorld::updateObjects()
{
	BASE_OBJECT* baseObject;
	PHYSICAL_OBJECT* physicalObject;
	for (int i = 0; i < objects.size(); i++)
	{
		baseObject = this->objects.findByIndex(i);
		physicalObject = this->objects.atIndex(i);

		baseObject->updatePhysicalObject(physicalObject);
		physicalObject->updateBaseObject(baseObject);
	}
}


void PhysicalWorld::setUpdateRate(unsigned int updateRate)
{
	this->updateRate = updateRate;
}
