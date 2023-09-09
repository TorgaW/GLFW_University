cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20) # min c++ standart is c++17

project(GLFW_Hello)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

set(ENGINE 
Object/Object.cpp
Shaders/Shaders.cpp)

add_executable(GLFW_Hello main.cpp glad.c ${ENGINE})
target_link_libraries(GLFW_Hello glfw OpenGL::GL)