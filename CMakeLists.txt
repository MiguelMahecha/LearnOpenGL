cmake_minimum_required(VERSION 3.29)
project(LearnOpenGL)

set(CMAKE_CXX_STANDARD 20)

# Add GLFW
add_subdirectory(libs/glfw-3.4)
include_directories(libs/glfw-3.4/include)

# Add GLAD
add_subdirectory(libs/glad)
include_directories(libs/glad/include)

add_executable(LearnOpenGL src/main.cpp)

# Link GLFW
target_link_libraries(LearnOpenGL glfw)

# Link GLAD
target_link_libraries(LearnOpenGL glad)