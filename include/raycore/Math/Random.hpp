#pragma once

#include <random>
#include <raycore\Math\Constants.hpp>
#include <raycore\Math\Vec3.hpp>

namespace rc::math
{
    class Random
    {
    public:
        inline static float get()
        {
            return dist(gen);
        }

        inline static float getInRange(float a, float b)
        {
            return a + (b - a) * get();
        }

        inline static Vec3 getSphere()
        {
            float theta = getInRange(0.f, math::twopi);
            float v = get();
            float phi = std::acos(2.f * v - 1.f);
            float r = std::cbrt(get());
            float sphi = r * sin(phi);
            float stheta = sin(theta);
            float cphi = r * cos(phi);
            float ctheta = cos(theta);

            return Vec3(sphi * ctheta,
                        sphi * stheta,
                        cphi);
        }

        inline static Vec3 getUnitVector()
        {
            return normalize(getSphere());
        }

    private:
        static std::uniform_real_distribution<float> dist;
        static std::mt19937 gen;
    };
}
