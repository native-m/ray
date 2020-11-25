#pragma once

#include <entt\entt.hpp>
#include <raycore\Camera.hpp>
#include <raycore\Intersection.hpp>
#include <raycore\Components\Transform.hpp>
#include <raycore\Components\IntersectionInvoker.hpp>

namespace rc
{
    class Scene
    {
    public:
        Scene();

        template<class ObjectT, class... Args>
        void addObject(const components::Transform& transform, Args&&... args);

        void setSkyColors(const math::Vec3& col0, const math::Vec3& col1);
        void render(int numSamples, const Camera& cam, uint32_t* pixels);

    private:
        math::Vec3 skyColor0        = math::Vec3(1.0f, 1.0f, 1.0f);
        math::Vec3 skyColor1        = math::Vec3(1.0f, 1.0f, 1.0f);
        entt::registry registry;

        using SceneView = decltype(registry.view<components::Transform, components::IntersectionInvoker>());

        void rayColor(const math::Ray& ray, const SceneView& view, math::Vec3& outColor, int depth);
        bool intersect(const math::Ray& ray, const SceneView& view, int depth, Intersection& intersection);
    };

    template<class ObjectT, class... Args>
    void Scene::addObject(const components::Transform& transform, Args&&... args)
    {
        auto entity = registry.create();
        auto& intersectionInvoker = registry.emplace<components::IntersectionInvoker>(entity);
        auto& object = registry.emplace<ObjectT>(entity, std::forward<Args>(args)...);

        registry.emplace<components::Transform>(entity, transform);
        intersectionInvoker.invoker.connect<&ObjectT::intersect>(object);
    }
}
