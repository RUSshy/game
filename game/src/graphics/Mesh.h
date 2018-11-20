#pragma once


#include <bgfx/bgfx.h>
#include <bgfx/platform.h>
#include "../../../libs/bgfx_cmake/bgfx/src/bgfx_p.h"

namespace game
{
    class Mesh
    {
    public:
        bgfx::VertexBuffer vBuffer;
        bgfx::IndexBuffer iBuffer;
    };
}