#pragma once
#include "ExternalInclude.h"
#include "SortableMap.h"

bool pollEvent()
{
	return true;
}

int main()
{
	SortableMap<string, int> map;
	map.push("Hallo", 2);
	map.push("Tschuess", 3);
	map.remove("Hallo");
	return 0;
}