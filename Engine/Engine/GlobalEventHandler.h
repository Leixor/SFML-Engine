#pragma once
#include "ExternalInclude.h"
#include "UnorderdMap.h"

class GlobalEventHandler
{
public:
	GlobalEventHandler();
	~GlobalEventHandler();

	static void addEvent(string name, function<void(void)> eventFunction);
	static void addEvent(string name, function<void(string[])> eventFunction);
	static void callEvent(string name);
	static void callEvent(string name, string args[]);

private:
	static UnorderdMap<string, function<void(void)>> eventFunctions;
	static UnorderdMap<string, function<void(string[])>> argEventFunctions;
};

