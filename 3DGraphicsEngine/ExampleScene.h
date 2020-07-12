#pragma once
#include "Scene.h"
#include "ExampleGround.h"
#include "ExampleBunny.h"


class ExampleScene : public Scene {
public:
	void Load(PObjectVec& objs, Player& player) override
	{
		std::shared_ptr<ExampleGround> ground(new ExampleGround());
		ground->scale *= 3.0f;
		objs.push_back(ground);

		std::shared_ptr<ExampleBunny> bunnylol(new ExampleBunny());
		bunnylol->scale *= 20.0f;
		bunnylol->RotateDegrees(0, 45.0f, 0);
		objs.push_back(bunnylol);

		player.SetPosition(Vector3(0, GH_PLAYER_HEIGHT, 5));
	}
};