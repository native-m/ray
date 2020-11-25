#pragma once

#include <raycore\Components\IntersectionInvoker.hpp>

namespace rc::object
{
    struct GroundPlane
    {
        math::Vec3 normal;

        GroundPlane(const math::Vec3& normal);

        bool intersect(const math::Ray& ray,
                       const components::Transform& transform,
                       float tmin,
                       float tmax,
                       Intersection& intersection) const;
    };
}
