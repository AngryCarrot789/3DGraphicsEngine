#pragma once
#include "GameHeader.h"
#include "Vector.h"
#include "Camera.h"
#include "CollisionSphere.h"
#include <vector>
#include <memory>

//Forward declarations
class Physical;
class Mesh;
class Texture;
class Shader;

// A class for creating objects in the game.
// These objects do not implement gravity
class GameObject {
public:
	GameObject();
	virtual ~GameObject() {}

	virtual void Reset();
	virtual void Draw(const Camera& cam, uint32_t curFBO);
	virtual void Update() {};
	virtual void OnHit(GameObject& other, Vector3& push) {};

	//Casts
	virtual Physical* AsPhysical() { return nullptr; }
	const Physical* AsPhysical() const { return const_cast<GameObject*>(this)->AsPhysical(); }

	void DebugDraw(const Camera& cam);

	Matrix4 LocalToWorld() const;
	Matrix4 WorldToLocal() const;
	Vector3 Forward() const;

	Vector3 pos;
	Vector3 euler;
	Vector3 scale;

	//not implemented.
	// rotation
	Vector3 rot;

	float p_scale;

	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Texture> texture;
	std::shared_ptr<Shader> shader;
};
typedef std::vector<std::shared_ptr<GameObject>> PObjectVec;
