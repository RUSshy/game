#include <bgfx/bgfx.h>
#include <bgfx/platform.h>


#include <fstream>
#include <string.h>
#include "Game.h"


const bgfx::Memory* loadMem( const char* filename )
{
    std::ifstream file( filename, std::ios::binary | std::ios::ate );
    std::streamsize size = file.tellg();
    file.seekg( 0, std::ios::beg );
    const bgfx::Memory* mem = bgfx::alloc( uint32_t( size + 1 ) );
    if ( file.read( ( char* )mem->data, size ) )
    {
        mem->data[ mem->size - 1 ] = '\0';
        return mem;
    }
    return nullptr;
}

bgfx::ShaderHandle loadShader( const char* shader )
{
    return bgfx::createShader( loadMem( shader ) );
}

bgfx::ProgramHandle loadProgram( const char* vsName, const char* fsName )
{
    bgfx::ShaderHandle vs = loadShader( vsName );
    bgfx::ShaderHandle fs = loadShader( fsName );
    return createProgram( vs, fs, true );
}


int main( int argc, char** argv )
{
    game::Game app;
    return app.run( argc, argv );
}