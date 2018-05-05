#include "Scene.h"

Scene::Scene()
{
}

Scene::~Scene()
{
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
