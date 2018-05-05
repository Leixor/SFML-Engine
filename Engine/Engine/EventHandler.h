#pragma once
#include "UnorderdMap.h"

class EventHandler
{
public:
	EventHandler();
	~EventHandler();

	void addEvent(string name, function<void(void)> eventFunction);
	void addEvent(string name, function<void(string[])> eventFunction);
	void callEvent(string name);
	void callEvent(string name, string args[]);

protected:
	UnorderdMap<string, function<void(void)>> eventFunctions;
	UnorderdMap<string, function<void(string[])>> argEventFunctions;
};

