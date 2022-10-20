cmake_minimum_required(VERSION 3.20)
project(raytracer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_STANDARD 17)

# require SDL2 library
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

# add internal project include directories
include_directories(include)

# create library
add_subdirectory(source)

# add executable
add_executable(raytracer raytracer.cpp)
target_link_libraries(raytracer PRIVATE libraytracer)
target_link_libraries(raytracer PRIVATE ${SDL2_LIBRARIES})





