# Declare the version of the CMake API for forward-compatibility
cmake_minimum_required(VERSION 2.8)

# Declare the name of the CMake Project
project(pkmncpp_project)

# Add the directory to search for header files
include_directories(include)

# Define an executable target called hello_world_node
add_executable(pokemon_cpp Pokemon.cpp)
