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

	tmp->addSubAnimation("tmp2", new Animation(), 0);
	tmp->addSubAnimation("tmp3", new Animation(), 100);
	tmp->addKeyframe(0, [&] {tmp->getSubAnimation("tmp2")->setLooping(true); });
	tmp->addKeyframe(200, [&] {tmp->getSubAnimation("tmp2")->pause(); });
	tmp->addKeyframe(100, [&] {tmp->getSubAnimation("tmp3")->setLooping(true); });
	tmp->addKeyframe(600, [&] {tmp->getSubAnimation("tmp3")->pause(); });
	tmp->setUpdateRate(10);

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