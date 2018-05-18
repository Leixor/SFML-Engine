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
	tmp->keyframeHandler.addKeyframe(0, [&] {tmp->getSubAnimations()->at("tmp2")->setLooping(true); });
	tmp->keyframeHandler.addKeyframe(100, [&] {tmp->getSubAnimations()->at("tmp2")->pause(); });
	//tmp->setUpdateRate(20);

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