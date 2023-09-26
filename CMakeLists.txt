cmake_minimum_required(VERSION 3.25.3)
project(game)
set(CXX_STANDARD 20)
set(CMAKE_CXX_EXTENSIONS 20)
set(CMAKE_CXX_COMPILER_ID clang)
set(CMAKE_CXX_COMPILER_VERSION 12.3.0)
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SDL2_Image_INCLUDE_DIRS})
include_directories(${imgui_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
add_executable(game src/main.cpp)


target_link_libraries(
  game
  ${SDL2_LIBRARIES}
  ${SDL2_Image_LIBRARIES}
  glfw
  OpenGL::GL
)
