#include "SceneHandler.h"

SceneHandler::SceneHandler()
{
}

SceneHandler::~SceneHandler()
{
}

void SceneHandler::handleEvents(EVENT_CLASS eventType)
{
	for (unsigned int i = 0; i < SceneHandler::scenes.size(); i++)
	{
		if (SceneHandler::scenes.atIndex(i)->visibility & EVENTABLE)
		{
			SceneHandler::scenes.atIndex(i)->handleEvents(eventType);
		}
	}
}

void SceneHandler::handleInputs()
{
	for (unsigned int i = 0; i < SceneHandler::scenes.size(); i++)
	{
		if (SceneHandler::scenes.atIndex(i)->visibility & INPUTABLE)
		{
			SceneHandler::scenes.atIndex(i)->handleInputs();
		}
	}
}

void SceneHandler::update()
{
	for (unsigned int i = 0; i < SceneHandler::scenes.size(); i++)
	{
		if (SceneHandler::scenes.atIndex(i)->visibility & UPDATABLE)
		{
			SceneHandler::scenes.atIndex(i)->updateSync();
		}
	}
}

void SceneHandler::draw()
{
	for (unsigned int i = 0; i < SceneHandler::scenes.size(); i++)
	{
		if (SceneHandler::scenes.atIndex(i)->visibility & DRAWABLE)
		{
			SceneHandler::scenes.atIndex(i)->draw();
		}
	}
}

void SceneHandler::deleteScene(string sceneName)
{
	SceneHandler::scenes.removeAt(sceneName);
}

void SceneHandler::setScenePriority(string name, int priority)
{
	SceneHandler::scenes.setIndex(name, priority);
}

void SceneHandler::setSceneVisibility(string name, Visibility visible)
{
	SceneHandler::scenes.at(name)->visibility = visible;
}

Scene * SceneHandler::getSceneByName(string name)
{
	return SceneHandler::scenes.at(name);
}

bool SceneHandler::sceneExists(string name)
{
	return SceneHandler::scenes.itemExists(name);
}



SortableMap<string, Scene*> SceneHandler::scenes;
