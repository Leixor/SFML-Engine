#include "GlobalEventHandler.h"

GlobalEventHandler::GlobalEventHandler()
{
}

GlobalEventHandler::~GlobalEventHandler()
{
}

void GlobalEventHandler::addEvent(string name, function<void(void)> eventFunction)
{
	GlobalEventHandler::eventFunctions.push(name, eventFunction);
}

void GlobalEventHandler::addEvent(string name, function<void(string[])> eventFunction)
{
	GlobalEventHandler::argEventFunctions.push(name, eventFunction);
}

void GlobalEventHandler::callEvent(string name)
{
	GlobalEventHandler::eventFunctions.at(name)();
}

void GlobalEventHandler::callEvent(string name, string args[])
{
	GlobalEventHandler::argEventFunctions.at(name)(args);
}

SortableMap<string, function<void(void)>> GlobalEventHandler::eventFunctions;
SortableMap<string, function<void(string[])>> GlobalEventHandler::argEventFunctions;