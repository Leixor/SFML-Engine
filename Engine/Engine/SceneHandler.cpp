#include "SceneHandler.h"

SceneHandler::SceneHandler()
{
}

SceneHandler::~SceneHandler()
{
}

void SceneHandler::update()
{
	for (unsigned int i = 0; i < SceneHandler::scenes.size(); i++)
	{
		if (SceneHandler::scenes.get(i)->sceneVisibility & UPDATABLE)
		{
			SceneHandler::scenes.get(i)->updateSync();
		}
	}
}

void SceneHandler::deleteScene(string sceneName)
{
	SceneHandler::scenes.remove(sceneName);
}

void SceneHandler::setScenePriority(string name, int priority)
{
	SceneHandler::scenes.setPriority(name, priority);
}

void SceneHandler::setSceneVisibility(string name, Visibility visible)
{
	SceneHandler::scenes.get(name)->sceneVisibility = visible;
}

Scene * SceneHandler::getSceneByName(string name)
{
	return SceneHandler::scenes.get(name);
}

bool SceneHandler::sceneExists(string name)
{
	return SceneHandler::scenes.itemExists(name);
}

UnorderdMap<string, Scene*> SceneHandler::scenes;
