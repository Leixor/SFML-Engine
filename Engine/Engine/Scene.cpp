#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::update()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		this->objects.getContentByPriority(i)->update();
	}
}

void Scene::draw()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		this->objects.getContentByPriority(i)->draw();
	}
}

void Scene::handleEvents(LIBRARY_EVENT_CLASS eventType)
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		this->objects.getContentByPriority(i)->handleEvents(eventType);
	}
}

void Scene::handleInputs()
{
	for (unsigned int i = 0; i < this->objects.size(); i++)
	{
		this->objects.getContentByPriority(i)->handleInputs();
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
