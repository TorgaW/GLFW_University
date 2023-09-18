cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20) # min c++ standart is c++17

project(OpenGL_3DView)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

set(CORE
Engine/Engine.cpp
Engine/Mesh/Mesh.cpp
Engine/Camera/Camera.cpp
Engine/Render/Render.cpp
Engine/Shader/Shader.cpp)

set(MANAGERS
Engine/Managers/MeshManager/MeshManager.cpp
Engine/Managers/CameraManager/CameraManager.cpp
Engine/Managers/ShaderManager/ShaderManager.cpp)

set(UTILS
Engine/Utils/OBJLoader/OBJLoader.cpp)

set(ENGINE ${CORE} ${MANAGERS} ${UTILS})

add_executable(OpenGL_3DView main.cpp glad.c ${ENGINE})
target_link_libraries(OpenGL_3DView glfw OpenGL::GL)

# command to update resources every build
add_custom_command(
        TARGET OpenGL_3DView PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
                ${CMAKE_SOURCE_DIR}/Resources
                ${CMAKE_CURRENT_BINARY_DIR}/Resources)