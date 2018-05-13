#pragma once

#include "ExternalInclude.h"
#include "EngineSetup.h"
#include "SceneHandler.h"


class GameEngine
{
public:
	GameEngine();
	~GameEngine();


	virtual void loop();

	virtual void handleEvents();
	virtual void handleInputs();
	virtual void update();
	virtual void render();

	long long getCurrentTime();

	virtual void createWindow() = 0;

	static WINDOW_CLASS* const getWindow();

	static WINDOW_CLASS* window;
	long long lag;
	long long previous;
};
