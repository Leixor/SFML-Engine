#pragma once
#include "ExternalInclude.h"
#include "GlobalEnums.h"
#include "GameEngine.h"

bool pollEvent()
{
	return true;
}

int main()
{
	GameEngine engine;
	engine.loop();
}