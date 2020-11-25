#include <raycore\Scene.hpp>
#include <raycore\Math\Ray.hpp>
#include <raycore\Math\CommonFunc.hpp>
#include <raycore\Math\Random.hpp>

#include <iostream>

namespace rc
{
    Scene::Scene()
    {
    }

    void Scene::setSkyColors(const math::Vec3& col0, const math::Vec3& col1)
    {
        skyColor0 = col0;
        skyColor1 = col1;
    }

    void Scene::render(int numSamples, const Camera& cam, uint32_t* pixels)
    {
        float w = cam.getWidth();
        float h = cam.getHeight();
        size_t iw = static_cast<size_t>(w);
        auto view = registry.view<components::Transform, components::IntersectionInvoker>();

        for (float y = 0; y < h; y += 1.0f) {
            float progress = std::round(y * 100.f / h);

            for (float x = 0; x < w; x += 1.0f) {
                math::Vec3 color;
                math::Vec3 tmpColor(0);
                size_t ix = static_cast<size_t>(x);
                size_t iy = static_cast<size_t>(y);

                // monte-carlo method
                for (int s = 0; s < numSamples; s++) {
                    float u = x + math::Random::get();
                    float v = y + math::Random::get();
                    rayColor(cam.getRay(u, v), view, tmpColor, 50);
                    color += tmpColor;
                }

                color = color / static_cast<float>(numSamples);
                
                pixels[iy * iw + ix] = (((uint32_t)(std::sqrt(color.x) * 255.f) & 255))
                                     | (((uint32_t)(std::sqrt(color.y) * 255.f) & 255) << 8)
                                     | (((uint32_t)(std::sqrt(color.z) * 255.f) & 255) << 16)
                                     | 255 << 24;
            }

            std::printf("\rRendering: %2.f%%", progress);
        }

        std::printf("\n");
    }

    void Scene::rayColor(const math::Ray& ray, const SceneView& view, math::Vec3& outColor, int depth)
    {
        math::Vec3 color;
        Intersection intersection;

        if (depth <= 0) {
            outColor = math::Vec3();
            return;
        }

        // trace light bounce
        // also, can we make this iterative?
        if (intersect(ray, view, depth, intersection)) {
            math::Vec3 target = intersection.p + intersection.normal + math::Random::getUnitVector();
            rayColor(math::Ray(intersection.p, target - intersection.p), view, color, depth - 1);
            color *= 0.5;
        }
        else {
            color = math::clamp(math::lerp(skyColor1, skyColor0, (ray.direction.y + 1.f) * 0.5f), skyColor0, skyColor1);
        }

        outColor = math::clamp(color, 0.0f, 1.0f);
    }

    bool Scene::intersect(const math::Ray& ray, const SceneView& view, int depth, Intersection& intersection)
    {
        math::Vec3 color;
        Intersection tmpIntersect;
        bool intersect = false;
        float closestHit = rc::math::inf;

        for (auto entity : view) {
            const auto [transform, intersectionInvoker] = view.get<components::Transform, components::IntersectionInvoker>(entity);

            if (intersectionInvoker.invoker(ray, transform, 0.000001f, closestHit, tmpIntersect)) {
                intersect = true;
                closestHit = tmpIntersect.t;
                intersection = tmpIntersect;
            }
        }

        return intersect;
    }
}
