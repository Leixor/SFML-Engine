#pragma once

enum Visibility
{
	NONE = 0,
	EVENTABLE = 1,
	INPUTABLE = 2,
	UPDATABLE = 4,
	DRAWABLE = 8,
	ALL = 15
};