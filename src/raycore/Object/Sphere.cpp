#include <raycore\Object\Sphere.hpp>

namespace rc::object
{
    Sphere::Sphere(float radius) :
        radius(radius)
    {
    }

    bool Sphere::intersect(const math::Ray& ray,
                           const components::Transform& transform,
                           float tmin,
                           float tmax,
                           Intersection& intersection) const
    {
        math::Vec3 distance = ray.origin - transform.position;
        float a = math::lengthSq(ray.direction);
        float b = math::dot(distance, ray.direction);
        float c = math::lengthSq(distance) - radius * radius;
        float discriminant = b * b - a * c;
        float sqDiscr = 0.f;
        float root = 0.f;

        if (discriminant < 0.f) {
            return false;
        }

        sqDiscr = std::sqrt(discriminant);
        root = (-b - sqDiscr) / a;
        if (root < tmin || root > tmax) {
            root = (-b + sqDiscr) / a;
            if (root < tmin || root > tmax) {
                return false;
            }
        }

        intersection.t = root;
        intersection.p = ray.at(root);
        intersection.setFaceNormal(ray, (intersection.p - transform.position) / radius);

        return true;
    }
}
