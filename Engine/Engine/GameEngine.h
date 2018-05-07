#pragma once

#include "ExternalInclude.h"
#include "Frameworks.h"
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

	static LIBRARY_WINDOW_CLASS* createWindow();


	long long lag;
	long long previous;
};
