#pragma once

#include <bgfx/bgfx.h>
#include <bgfx/platform.h>

#define GLFW_EXPOSE_NATIVE_WIN32
#include <GLFW/glfw3.h>
#include <GLFW/glfw3native.h>

#include <fstream>
#include <cstring>

class Application
{
public:
    int run( int argc, char** argv )
    {
        // Initialize the glfw
        if ( !glfwInit() )
        {
            return -1;
        }

        // Create a window
        glfwWindowHint( GLFW_CLIENT_API, GLFW_NO_API );
        mWindow = glfwCreateWindow( 1280, 720, "PROJECT R", nullptr, nullptr);
        if ( !mWindow )
        {
            glfwTerminate();
            return -1;
        }

        // Setup bgfx
        bgfx::PlatformData platformData{};
        memset( &platformData, 0, sizeof( platformData ) );
        platformData.nwh = glfwGetWin32Window( mWindow );
        bgfx::setPlatformData( platformData );

        // Initialize the application
        initialize( argc, argv );

        // Loop until the user closes the window
        while ( !glfwWindowShouldClose( mWindow ) )
        {
            // Poll for and process events
            glfwPollEvents();
            update();
        }

        // Shutdown application and glfw
        int ret = shutdown();
        glfwTerminate();
        return ret;
    }

    virtual void initialize( int _argc, char** _argv ) = 0;
    virtual void update() = 0;
    virtual int shutdown() = 0;
protected:
    GLFWwindow* mWindow{};
};

