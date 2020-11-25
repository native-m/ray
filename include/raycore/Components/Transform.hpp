#pragma once

#include <raycore\Math\Vec3.hpp>

namespace rc::components
{
    struct Transform
    {
        math::Vec3 position;
        math::Vec3 rotation;

        Transform()
        {
        }

        Transform(const math::Vec3& position,
                  const math::Vec3& rotation) :
            position(position),
            rotation(rotation)
        {
        }

        Transform(const Transform& other) :
            position(other.position),
            rotation(other.rotation)
        {
        }
    };
}
