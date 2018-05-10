#pragma once
#include "BaseObject.h"

class BaseObject;

class PhysicalBaseObject
{
public:
	PhysicalBaseObject();
	~PhysicalBaseObject();

	virtual void updateBaseObject(BaseObject* Object);

	Visibility visibility;
};

