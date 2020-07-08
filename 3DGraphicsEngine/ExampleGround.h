#pragma once
#include "GameObject.h"
#include "Resources.h"

class ExampleGround : public GameObject {
public:
    ExampleGround(bool slope = false) {
        if (slope) {
            mesh = AquireMesh("ground_slope.obj");
        }
        else {
            mesh = AquireMesh("ground.obj");
        }
        shader = AquireShader("texture");
        texture = AquireTexture("checker_green.bmp");
        scale = Vector3(10, 1, 10);
    }
    virtual ~ExampleGround() {}
};
