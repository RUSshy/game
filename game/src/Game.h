#pragma once

#include "Application.h"
#include <entt/entt.hpp>
#include <cstdint>

namespace game
{
    struct position {
        float x;
        float y;
    };

    struct velocity {
        float dx;
        float dy;
    };

    class Game : public Application
    {
        void initialize( int _argc, char** _argv )
        {
            _width     = 1280;
            _height    = 720;
            _reset     = BGFX_RESET_VSYNC;
            _oldWidth  = _width;
            _oldHeight = _height;

            bgfx::Init init;
            init.type = bgfx::RendererType::Direct3D11;

            bgfx::init(init);
            bgfx::reset( _width, _height, _reset );
            bgfx::setViewClear( 0, BGFX_CLEAR_COLOR|BGFX_CLEAR_DEPTH, 0x000000ff, 1.0f, 0 );

            //m_program = loadProgram( "data/shaders/dx11/vs_debug.bin", "data/shaders/dx11/fs_debug.bin" );
        }

        int shutdown()
        {
            bgfx::shutdown();
            return 0;
        }

        void update()
        {
            int width, height;
            glfwGetWindowSize( mWindow, &width, &height );
            _width = width;
            _height = height;
            if ( ( _width != _oldWidth ) || ( _height != _oldHeight ) )
            {
                _oldWidth = _width;
                _oldHeight = _height;
                bgfx::reset( _width, _height, _reset );
            }

            bgfx::setViewRect( 0, 0, 0, uint16_t( _width ), uint16_t( _height ) );
            bgfx::touch( 0 );
            bgfx::frame();


            auto entity = registry.create();
            registry.assign<game::position>(entity, 0.0f, 0.0f);
        }


    public:
        entt::registry registry;

    private:
        uint32_t _width;
        uint32_t _height;
        uint32_t _reset;
        uint32_t _oldWidth;
        uint32_t _oldHeight;

        bgfx::ProgramHandle _program;
    };
}