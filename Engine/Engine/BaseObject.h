#pragma once
#include "GlobalEnums.h"
#include "EngineSetup.h"
#include PHYSICAL_OBJECT_INCLUDE

class PHYSICAL_OBJECT;

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	virtual void draw();
	virtual void update();
	virtual void handleEvents(EVENT_CLASS event);
	virtual void handleInputs();

	virtual void updatePhysicalObject(PHYSICAL_OBJECT* Object);
	
	Visibility visibility;

private:

};

