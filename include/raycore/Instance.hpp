#pragma once

#include <memory>

#include <raycore\Scene.hpp>
#include <raycore\Camera.hpp>

namespace rc
{
    class Instance
    {
    public:
        Instance();

        void createVertexBuffer();
        std::shared_ptr<Scene> createScene();
        void renderScene(int numSamples, const Camera& cam, const std::shared_ptr<Scene>& scene, std::unique_ptr<uint32_t>& pixels);
    };
}
