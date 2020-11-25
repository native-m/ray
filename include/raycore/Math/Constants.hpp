#pragma once

#include <limits>

namespace rc::math
{
    static constexpr float pi = 3.14159f;
    static constexpr float twopi = 2 * pi;
    static constexpr float pi2 = pi / 2.f;
    static constexpr float eps = std::numeric_limits<float>::epsilon();
    static constexpr float inf = std::numeric_limits<float>::max();
}
