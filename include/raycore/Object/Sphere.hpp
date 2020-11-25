#pragma once

#include <raycore\Components\IntersectionInvoker.hpp>

namespace rc::object
{
    struct Sphere
    {
        float radius;

        Sphere(float radius);

        bool intersect(const math::Ray& ray,
                       const components::Transform& transform,
                       float tmin,
                       float tmax,
                       Intersection& intersection) const;
    };
}
