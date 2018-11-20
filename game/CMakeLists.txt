project(game LANGUAGES CXX C)

include_directories("../libs/entt/src/")

add_executable(game
        src/main.cpp

        src/Game.cpp
        src/Game.h

        src/Application.h
        src/graphics/Mesh.h)


target_link_libraries(game glfw bgfx entt)


add_shader(data/vs_debug.sc VERTEX OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/data/shaders PLATFORMS dx11 glsl DX11_MODEL 5_0 GLSL 130)
add_shader(data/fs_debug.sc FRAGMENT OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/data/shaders PLATFORMS dx11 glsl DX11_MODEL 5_0 GLSL 130)

configure_debugging(game WORKING_DIR ${CMAKE_CURRENT_BINARY_DIR})