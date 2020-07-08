#include "GameObject.h"
#include "Mesh.h"
#include "Shader.h"
#include "Texture.h"

GameObject::GameObject() :
    pos(0.0f),
    euler(0.0f),
    scale(1.0f),
    p_scale(1.0f) {
}

void GameObject::Reset() {
    pos.SetZero();
    euler.SetZero();
    scale.SetOnes();
    p_scale = 1.0f;
}

void GameObject::Draw(const Camera& cam, uint32_t curFBO) {
    if (shader && mesh) {
        const Matrix4 mv = WorldToLocal().Transposed();
        const Matrix4 mvp = cam.Matrix() * LocalToWorld();
        shader->Use();
        if (texture) {
            texture->Use();
        }
        shader->SetMVP(mvp.m, mv.m);
        mesh->Draw();
    }
}

Vector3 GameObject::Forward() const {
    return -(Matrix4::RotZ(euler.z) * Matrix4::RotX(euler.x) * Matrix4::RotY(euler.y)).ZAxis();
}

Matrix4 GameObject::LocalToWorld() const {
    return Matrix4::Trans(pos) * Matrix4::RotY(euler.y) * Matrix4::RotX(euler.x) * Matrix4::RotZ(euler.z) * Matrix4::Scale(scale * p_scale);
}

Matrix4 GameObject::WorldToLocal() const {
    return Matrix4::Scale(1.0f / (scale * p_scale)) * Matrix4::RotZ(-euler.z) * Matrix4::RotX(-euler.x) * Matrix4::RotY(-euler.y) * Matrix4::Trans(-pos);
}

void GameObject::DebugDraw(const Camera& cam) {
    if (mesh) {
        mesh->DebugDraw(cam, LocalToWorld());
    }
}
