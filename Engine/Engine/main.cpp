#pragma once
#include "ExternalInclude.h"
#include "GlobalEnums.h"

int main()
{
	Visibility tmp;
	int g = VISIBLE;
	tmp = static_cast<Visibility>(g);

	if (tmp == VISIBLE)
		printf("HI");

	while (true)
	{
	}

	return 0;
}