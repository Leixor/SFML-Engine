#pragma once
#include "ExternalInclude.h"
#include "GlobalEnums.h"
#include "Frameworks.h"

bool pollEvent()
{
	return true;
}

int main()
{
	Visibility tmp;
	int g = VISIBLE;
	tmp = static_cast<Visibility>(g);

	if (tmp == VISIBLE)
		printf("HI");

	LIBRARY_WINDOW_CLASS i = 1;
	LIBRARY_EVENT_CLASS j = i;
	if(LIBRARY_POLLEVENT_FUNCTION())
		printf("%d", j);

	while (true)
	{
	}

	return 0;
}