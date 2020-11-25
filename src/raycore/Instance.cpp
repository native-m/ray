#include <stdexcept>
#include <raycore\Instance.hpp>

namespace rc
{
    Instance::Instance()
    {
    }

    std::shared_ptr<Scene> Instance::createScene()
    {
        return std::make_shared<Scene>();
    }

    void Instance::renderScene(int numSamples, const Camera& cam, const std::shared_ptr<Scene>& scene, std::unique_ptr<uint32_t>& pixels)
    {
        size_t w = static_cast<size_t>(cam.getWidth());
        size_t h = static_cast<size_t>(cam.getHeight());
        
        if (pixels != nullptr) {
            throw std::runtime_error("Pixel data is not nullptr");
        }

        pixels.reset(new uint32_t[w * h]);
        std::memset(pixels.get(), 0, w * h * 4);
        
        scene->render(numSamples, cam, pixels.get());
    }
}
