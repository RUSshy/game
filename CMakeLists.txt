cmake_minimum_required(VERSION 3.12)
project(rpg_cpp)

set(CMAKE_CXX_STANDARD 17)


set(BGFX_BUILD_TOOLS ON CACHE INTERNAL "")
set(BGFX_BUILD_EXAMPLES ON CACHE INTERNAL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "")
set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "")
set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "")
set(GLFW_INSTALL OFF CACHE INTERNAL "")

add_subdirectory(libs/bgfx.cmake)
add_subdirectory(libs/glfw)
add_subdirectory(libs/entt)

add_subdirectory(game)