#pragma once
#include "GameObject.h"
#include "Player.h"

// A base class used for storing scenery data. 
// Create your own scene class and inherit this, like in ExampleScene.
class Scene {
public:
	virtual void Load(PObjectVec& objs, Player& player) {};
	virtual void Unload() {};
};
