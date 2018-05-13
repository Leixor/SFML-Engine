#pragma once
#include "ExternalInclude.h"
#include "SortableMap.h"
#include "GameEngine.h"
#include "AnimationHandler.h"

class A
{
public:
	function<void(void)> action;
};

class C
{

};

class B
{
public:
	A* a;

	void machAction()
	{
		a = new A();
		a->action = [&]() {this->dieAction();};
		a->action();
	}

protected:
	void dieAction()
	{
		printf("%d", )
	}
};

int main()
{
	AnimationHandler handler;
	Animation* tmp = new Animation();
	tmp->addObject(new AnimationObject());

	Animation* tmp2 = tmp->addAnimation("tmp2", false);
	tmp2->addAnimation("tmp3", false);
	tmp2->addKeyframe("tmp3", ANILOOPING, 0);
	tmp2->addKeyframe("tmp3", ANIPAUSE, 100);

	tmp->addKeyframe("tmp2", ANISTART, 200);
	tmp->addKeyframe("tmp2", ANILOOPING, 200);
	tmp->addKeyframe("tmp2", ANIPAUSE, 400);
	tmp->setUpdateRate(20);

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