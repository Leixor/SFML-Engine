#include "EventHandler.h"

EventHandler::EventHandler()
{
}

EventHandler::~EventHandler()
{
}

void EventHandler::addEvent(string name, function<void(void)> eventFunction)
{
	this->eventFunctions.push(name, eventFunction);
}

void EventHandler::addEvent(string name, function<void(string[])> eventFunction)
{
	this->argEventFunctions.push(name, eventFunction);
}

void EventHandler::callEvent(string name)
{
	this->eventFunctions.at(name)();
}

void EventHandler::callEvent(string name, string args[])
{
	this->argEventFunctions.at(name)(args);
}
