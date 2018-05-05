#pragma once
#include "Scene.h"
#include "UnorderdMap.h"
#include "GlobalEnums.h"

class Scene;
class SceneHandler
{
public:
	SceneHandler();
	~SceneHandler();

	static void update();
	static void draw();
	static void handleEvents();
	static void handleInput();

	template <typename SceneType>
	static SceneType addScene(string name, SceneType scene, Visibility visible = ALL);
	template <typename SceneType>
	static SceneType addScene(string name, SceneType scene, int priority, Visibility visible = ALL);

	static void deleteScene(string sceneName);
	static void setScenePriority(string name, int priority);
	static void setSceneVisibility(string name, Visibility visible);

	static Scene* getSceneByName(string name);
	static bool sceneExists(string name);
protected:
	static UnorderdMap<string, Scene*> scenes;
};

template<typename SceneType>
inline SceneType SceneHandler::addScene(string name, SceneType scene, Visibility visible)
{
	SceneHandler::scenes.push(name, scene);
	SceneHandler::setSceneVisibility(name, visible);
	return scene;
}

template<typename SceneType>
inline SceneType SceneHandler::addScene(string name, SceneType scene, int priority, Visibility visible)
{
	SceneHandler::scenes.push(name, scene);
	SceneHandler::setSceneVisibility(name, visible);
	SceneHandler::setScenePriority(name, priority);
	return scene;
}
