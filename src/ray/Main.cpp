#include <iostream>
#include <fstream>
#include <raycore\Instance.hpp>
#include <raycore\Math\CommonFunc.hpp>
#include <raycore\Object\GroundPlane.hpp>
#include <raycore\Object\Sphere.hpp>
#include <raycore\Utils\ImageIO.hpp>

int main()
{
    rc::Instance instance;
    rc::Camera camera(800.f, 640.f);
    std::shared_ptr<rc::Scene> scene = instance.createScene();
    std::unique_ptr<uint32_t> pixels;

    scene->addObject<rc::object::GroundPlane>(rc::components::Transform(rc::math::Vec3(0.f, -1.f, 0.f), rc::math::Vec3(0.f, 0.f, 0.f)),
                                              rc::math::Vec3(0.f, 1.f, 0.f));
    scene->addObject<rc::object::Sphere>(rc::components::Transform(rc::math::Vec3(0.f, 0.0f, -2.f), rc::math::Vec3(0.f, 0.f, 0.f)),
                                         1.f);

    scene->setSkyColors(rc::math::colorToVec3(123, 175, 207), rc::math::colorToVec3(237, 242, 241));

    instance.renderScene(10, camera, scene, pixels); // num of samples, camera, scene, final image

    rc::utils::ImageIO::write(rc::utils::ImageIO::BMP,
                              "test.bmp",
                              static_cast<int>(camera.getWidth()),
                              static_cast<int>(camera.getHeight()),
                              pixels);

    return 0;
}
