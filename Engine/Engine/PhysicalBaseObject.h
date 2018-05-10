#pragma once
#include "GlobalEnums.h"
#include "EngineSetup.h"
#include BASE_OBJECT_INCLUDE

class BASE_OBJECT;

class PhysicalBaseObject
{
public:
	PhysicalBaseObject();
	~PhysicalBaseObject();

	virtual void updateBaseObject(BASE_OBJECT* Object);

	Visibility visibility;
};

