#pragma once
#include "GameObject.h"
#include "CollisionSphere.h"

class Physical : public GameObject {
public:
    Physical();
    virtual ~Physical() override {}

    virtual void Reset() override;
    virtual void Update() override;
    virtual void OnCollide(GameObject& other, const Vector3& push);

    void SetPosition(const Vector3& _pos) {
        pos = _pos;
        prev_pos = _pos;
    }

    virtual Physical* AsPhysical() override { return this; }

    Vector3 gravity;
    Vector3 velocity;
    float bounce;
    float friction;
    float high_friction;
    float drag;

    Vector3 prev_pos;

    std::vector<CollisionSphere> hitSpheres;
};
