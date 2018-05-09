#include "PhysicalWorld.h"


PhysicalWorld::PhysicalWorld(Scene * scene) : scene(scene)
{
}

PhysicalWorld::~PhysicalWorld()
{
}

PhysicalBaseObject* PhysicalWorld::addPhysicalObject(string baseObjectName, PhysicalBaseObject* object)
{
	this->objects.push(baseObjectName, object);
	return object;
}

void PhysicalWorld::updatePhysicalWorld()
{
}

void PhysicalWorld::updateObjects()
{
	BaseObject* baseObject;
	PhysicalBaseObject* physicalObject;
	for (int i = 0; i < objects.size(); i++)
	{
		baseObject = scene->getObjectByName(this->objects.getIterator(i));
		physicalObject = this->objects.get(i);

		baseObject->updatePhysicalObject(physicalObject);
		physicalObject->updateBaseObject(baseObject);
	}
}

void PhysicalWorld::setUpdateRate(unsigned int updateRate)
{
	this->updateRate = updateRate;
}
