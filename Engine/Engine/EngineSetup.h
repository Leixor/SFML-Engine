#pragma once

#define WINDOW_CLASS int
#define EVENT_CLASS int
#define POLLEVENT_FUNCTION GameEngine::createWindow
#define WINDOWOPEN_FUNCTION GameEngine::getWindow
#define CREATEWINDOW_FUNCTION GameEngine::createWindow

#define PHYSICAL_WORLD_CLASS string
#define PHYSICAL_WORLD_INCLUDE "BaseObject.h"
#define BASE_OBJECT BaseObject
#define BASE_OBJECT_INCLUDE "BaseObject.h"
#define PHYSICAL_OBJECT PhysicalBaseObject
#define PHYSICAL_OBJECT_INCLUDE "PhysicalBaseObject.h"
