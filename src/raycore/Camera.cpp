#include <raycore\Camera.hpp>

namespace rc
{
    Camera::Camera(float w, float h, float fov) :
        width(w),
        height(h),
        fov(std::tan(fov / 2.f)),
        aspectRatio(w / h)
    {
    }

    void Camera::setPosition(const math::Vec3& position)
    {
        pos = position;
    }

    void Camera::setSize(float w, float h)
    {
        width = w;
        height = h;
        aspectRatio = w / h;
    }

    void Camera::setFovAngle(float fovAngle)
    {
        fov = std::tan(fov / 2.f);
    }

    math::Ray Camera::getRay(float x, float y) const
    {
        float pixelNdcX = (x + 0.5f) / width;
        float pixelNdcY = (y + 0.5f) / height;
        float pixelScreenX = 2.f * pixelNdcX - 1.f;
        float pixelScreenY = 1.f - 2.f * pixelNdcY;
        float pixelCameraX = pixelScreenX * aspectRatio * fov;
        float pixelCameraY = pixelScreenY * fov;
        math::Vec3 dir(pixelCameraX, pixelCameraY, -1.f);

        return math::Ray(pos, dir - pos);
    }
}
