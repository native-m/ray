#pragma once

#include <memory>
#include <string>

namespace rc::utils
{
    struct ImageIO
    {
        enum Type
        {
            PNG = 0,
            BMP,
            TGA,
            JPG
        };

        static bool write(uint32_t type, const std::string& filepath, int w, int h, const std::unique_ptr<uint32_t>& pixels);
        static bool read(const std::string& filepath, std::unique_ptr<uint32_t>& pixels);
    };
}
