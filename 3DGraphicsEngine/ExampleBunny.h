#pragma once
#include "GameObject.h"
#include "Resources.h"

class ExampleBunny : public GameObject {
public:
    ExampleBunny() {
        mesh = AquireMesh("floorplan.obj");
        shader = AquireShader("texture_array");
        texture = AquireTexture("floorplan_textures.bmp", 4, 4);
        scale = Vector3(2, 2, 2);
    }
    virtual ~ExampleBunny() {}
};