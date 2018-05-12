#pragma once
#include "ExternalInclude.h"
#include "SortableMap.h"
#include "GameEngine.h"
#include "AnimationHandler.h"

int main()
{
	AnimationHandler handler;
	Animation* tmp = new Animation();
	tmp->addObject(new AnimationObject());
	Animation* tmp2 = tmp->addAnimation("tmp2");
	tmp2->addAnimation("tmp3");
	tmp2->addKeyframe("tmp3", ANILOOPING, 0);
	tmp2->addKeyframe("tmp3", ANIPAUSE, 100);

	handler.addAnimation("tmp", tmp);
	handler.run("tmp");
	for (int i = 0; i < 1000; i++)
	{
		if (handler.update())
		{
			printf("%d", i);
			int k = 0;
		}
	}
	return 0;
}