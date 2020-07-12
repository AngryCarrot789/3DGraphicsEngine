#pragma once
#include "GameObject.h"
#include "Resources.h"

class ExampleBunny : public Physical {
public:
    float cc;
    ExampleBunny() {
        mesh = AquireMesh("bunny.obj");
        shader = AquireShader("texture");
        texture = AquireTexture("gold.bmp");
        pos = Vector3(0, 5.0f, 0);
        scale = Vector3(1, 1, 1);
    }

    virtual ~ExampleBunny() {}
};