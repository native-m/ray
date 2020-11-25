#pragma once

#include <entt\entt.hpp>
#include <raycore\Math\Ray.hpp>

namespace rc
{
    struct Intersection
    {
        math::Vec3 p;
        math::Vec3 normal;
        float t;
        bool frontFace;

        Intersection() :
            p(),
            normal(),
            t(0),
            frontFace(false)
        {
        }

        Intersection(const math::Vec3& p, const math::Vec3& normal, float t) :
            p(p),
            normal(normal),
            t(t),
            frontFace(false)
        {
        }

        Intersection(const Intersection& other) :
            p(other.p),
            normal(other.normal),
            t(other.t),
            frontFace(false)
        {
        }

        inline void setFaceNormal(const math::Ray& ray, const math::Vec3& outwardNormal)
        {
            frontFace = math::dot(ray.direction, outwardNormal) < 0.f;
            normal = frontFace ? outwardNormal : -outwardNormal;
        }
    };
}
