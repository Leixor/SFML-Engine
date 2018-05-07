#pragma once
#include "BaseObject.h"
#include "Header.h"

template <class LibraryWindow>
class Window : public LibraryWindowClass
{
public:
	Window();
	~Window();

	virtual void draw(BaseObject& drawableObject) = 0;
	virtual void handleEvent(BaseObject&  drawableObject) = 0;

	virtual LibraryWindow* getLibraryWindow() = 0;
};