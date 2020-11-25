#pragma once

#include <raycore\Object\GroundPlane.hpp>

namespace rc::object
{
    GroundPlane::GroundPlane(const math::Vec3& normal) :
        normal(normal)
    {
    }

    bool GroundPlane::intersect(const math::Ray& ray,
                                const components::Transform& transform,
                                float tmin,
                                float tmax,
                                Intersection& intersection) const
    {
        float dn = math::dot(ray.direction, normal);
        float t = dot(transform.position - ray.origin, normal) / dn;

        if (t <= tmin || t >= tmax) {
            return false;
        }

        intersection.t = t;
        intersection.p = ray.at(t);
        intersection.normal = normal;

        return true;
    }
}
