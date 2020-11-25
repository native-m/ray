#include <raycore\Utils\ImageIO.hpp>
#include "StbStub.hpp"

namespace rc::utils
{
    bool ImageIO::write(uint32_t type, const std::string& filepath, int w, int h, const std::unique_ptr<uint32_t>& pixels)
    {
        const void* data = reinterpret_cast<const void*>(pixels.get());

        switch (type) {
            case Type::PNG:
                return stbi_write_png(filepath.c_str(), w, h, STBI_rgb_alpha, data, 4) == 1;
            case Type::BMP:
                return stbi_write_bmp(filepath.c_str(), w, h, STBI_rgb_alpha, data) == 1;
            case Type::TGA:
                return stbi_write_tga(filepath.c_str(), w, h, STBI_rgb_alpha, data) == 1;
            case Type::JPG:
                return stbi_write_jpg(filepath.c_str(), w, h, STBI_rgb_alpha, data, 100) == 1;
        }

        return false;
    }

    bool ImageIO::read(const std::string& filepath, std::unique_ptr<uint32_t>& pixels)
    {
        return false;
    }
}
