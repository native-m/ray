#pragma once

#include <raycore\Intersection.hpp>
#include <raycore\Math\Ray.hpp>
#include <raycore\Components\Transform.hpp>

namespace rc::components
{
    using IntersectionDelegate = entt::delegate<bool(const math::Ray&, const components::Transform&, float, float, Intersection&)>;

    struct IntersectionInvoker
    {
        IntersectionDelegate invoker;
    };
}
