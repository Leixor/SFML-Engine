#pragma once
#include "ExternalInclude.h"
#include "SortableMap.h"
#include "GameEngine.h"
#include "AnimationHandler.h"

int main()
{
	AnimationHandler handler;
	Animation* Oberanimation = new Animation();
	Oberanimation->addObject(new AnimationObject());

	Animation* Unteranimation = Oberanimation->addSubAnimation("Unteranimation", new Animation(), 0);
	Unteranimation->addObject(new AnimationObject());
	Unteranimation->addObject(new AnimationObject());

	Oberanimation->addKeyframe(0, [&] {Oberanimation->getSubAnimation("Unteranimation")->setLooping(true);});
	Oberanimation->addKeyframe(600, [&] {Oberanimation->getSubAnimation("Unteranimation")->setLooping(false);});
	Oberanimation->addKeyframe(600, [&] {Oberanimation->getSubAnimation("Unteranimation")->pause();});

	Animation* UnterUnterAnimation = new Animation();
	*UnterUnterAnimation = *Unteranimation;
	Unteranimation->addSubAnimation("UnterUnterAnimation", UnterUnterAnimation);
	UnterUnterAnimation->addObject(new AnimationObject());

	Unteranimation->addKeyframe(0, [&] {Unteranimation->getSubAnimation("UnterUnterAnimation")->setLooping(true); });
	Unteranimation->addKeyframe(800, [&] {Unteranimation->getSubAnimation("UnterUnterAnimation")->setLooping(false);});

	Oberanimation->setUpdateRate(100);

	handler.addAnimation("tmp", Oberanimation);
	handler.run("tmp");

	for (int i = 0; i < 1000; i++)
	{
		if (!handler.update())
		{
			printf("%d", i);
			int k = 0;
		}
	}
	return 0;
}