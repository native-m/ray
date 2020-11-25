#pragma once

#include <raycore\Math\Vec3.hpp>
#include <string>
#include <unordered_map>

namespace rc::utils
{
    class VertexBuffer
    {
    public:
        VertexBuffer();

        template<class AttribT>
        void addAttribute(const std::string& name);

        template<class AttribT>
        AttribT* getAttribute(const std::string& name) const;

    private:
        std::unordered_map<std::string, void*> attributes;
    };
}
