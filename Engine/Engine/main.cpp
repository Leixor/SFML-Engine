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

	Animation* bsp1 = tmp->addSubAnimation("bsp1", new Animation(), 100);
	bsp1->addObject(new AnimationObject());

	tmp->addKeyframe(100, [&] {	tmp->getSubAnimation("bsp1")->setLooping(true); });
	tmp->addKeyframe(600, [&] {tmp->getSubAnimation("bsp1")->pause(); });

	Animation* bsp2 = new Animation(*bsp1);
	bsp1->addSubAnimation("bsp2", bsp2);

	bsp1->addKeyframe(0, [&] {bsp1->getSubAnimation("bsp2")->setLooping(true); });
	bsp1->addKeyframe(800, [&] {bsp1->getSubAnimation("bsp2")->pause(); });

	tmp->setUpdateRate(100);

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