#pragma once
#include "Frameworks.h"
#include "GlobalEnums.h"

class BaseObject
{
public:
	BaseObject();
	~BaseObject();

	virtual void draw();
	virtual void update();
	virtual void handleEvents(LIBRARY_EVENT_CLASS event);
	virtual void handleInputs();

	Visibility visibility;
};

