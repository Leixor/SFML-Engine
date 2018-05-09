#include "Scene.h"

Scene::Scene()
{
	this->updateCount = 1;
	this->updateRate = MS_PER_UPDATE;
}

Scene::~Scene()
{
}

void Scene::handleEvents(LIBRARY_EVENT_CLASS eventType)
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.get(i)->visibility & EVENTABLE)
		{
			this->objects.getContentByPriority(i)->handleEvents(eventType);
		}
	}
}

void Scene::handleInputs()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.get(i)->visibility & INPUTABLE)
		{
			this->objects.getContentByPriority(i)->handleInputs();
		}
	}
}

void Scene::update()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.get(i)->visibility & UPDATABLE)
		{
			this->objects.getContentByPriority(i)->update();
		}
	}
}

void Scene::draw()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		if (this->objects.get(i)->visibility & DRAWABLE)
		{
			this->objects.getContentByPriority(i)->draw();
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
	return this->objects.get(name);
}

