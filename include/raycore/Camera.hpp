#pragma once

#include <raycore\Math\Constants.hpp>
#include <raycore\Math\Ray.hpp>

namespace rc
{
    class Camera
    {
    public:
        Camera(float w, float h, float fov = rc::math::pi2);

        void setPosition(const math::Vec3& position);
        void setSize(float w, float h);
        void setFovAngle(float fovAngle);

        float getWidth() const { return width; }
        float getHeight() const { return height; }
        math::Ray getRay(float x, float y) const;

    private:
        math::Vec3 pos;
        float width;
        float height;
        float fov;
        float aspectRatio;
    };
}
