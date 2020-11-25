#pragma once

#include <raycore\Math\Random.hpp>

namespace rc::math
{
    std::uniform_real_distribution<float> Random::dist = std::uniform_real_distribution<float>(0.0f, 1.0f);
    std::mt19937 Random::gen;
}
