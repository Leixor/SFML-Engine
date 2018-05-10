#include "Scene.h"

Scene::Scene()
{
	this->updateCount = 1;
	this->updateRate = MS_PER_UPDATE;
}

Scene::~Scene()
{
}

void Scene::handleEvents(EVENT_CLASS eventType)
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.atIndex(i)->visibility & EVENTABLE)
		{
			this->objects.atIndex(i)->handleEvents(eventType);
		}
	}
}

void Scene::handleInputs()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.atIndex(i)->visibility & INPUTABLE)
		{
			this->objects.atIndex(i)->handleInputs();
		}
	}
}

void Scene::update()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.atIndex(i)->visibility & UPDATABLE)
		{
			this->objects.atIndex(i)->update();
		}
	}
}

void Scene::draw()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.atIndex(i)->visibility & DRAWABLE)
		{
			this->objects.atIndex(i)->draw();
		}
	}
}





void Scene::updateSync()
{
	if (updateCount >= updateRate / MS_PER_UPDATE)
	{
		this->update();
		updateCount = 1;
	}
	else
	{
		updateCount++;
	}
}

BaseObject * Scene::getObjectByName(string name)
{
	return this->objects.at(name);
}

