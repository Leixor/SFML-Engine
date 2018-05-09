#pragma once
#include "Frameworks.h"
#include "GlobalEnums.h"
#include "ExternalInclude.h"
#include "PhysicalBaseObject.h"

class PhysicalBaseObject;

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	virtual void draw();
	virtual void update();
	virtual void handleEvents(LIBRARY_EVENT_CLASS event);
	virtual void handleInputs();

	virtual void updatePhysicalObject(PhysicalBaseObject* Object);
	
	Visibility visibility;

private:

};

