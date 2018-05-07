#include "GameEngine.h"



GameEngine::GameEngine()
{
	this->lag = 0;
	this->previous = this->getCurrentTime();
}


GameEngine::~GameEngine()
{
}

void GameEngine::loop()
{
	while (LIBRARY_WINDOWOPEN_FUNCTION())
	{
		long long current = getCurrentTime();
		long long elapsed = current - previous;
		previous = current;
		lag += elapsed;

		this->handleEvents();
		this->handleInputs();
		this->update();
		this->render();
	}
}

void GameEngine::handleEvents()
{
}

void GameEngine::handleInputs()
{
	SceneHandler::handleInputs();
}

void GameEngine::update()
{
	while (lag >= MS_PER_UPDATE)
	{
		SceneHandler::update();
		lag -= MS_PER_UPDATE;
	}
}

void GameEngine::render()
{

}

long long GameEngine::getCurrentTime()
{
		chrono::milliseconds ms = chrono::duration_cast<chrono::milliseconds>(
			chrono::system_clock::now().time_since_epoch()
		);
		return ms.count();
}

LIBRARY_WINDOW_CLASS * GameEngine::createWindow()
{
	return nullptr;
}
