cmake_minimum_required(VERSION 3.5)
project(Algorithms) # Project name
set(CMAKE_CXX_FLAGS "-Wextra -Wall -Werror -pedantic -std=c++11") # Compilation flags

file(GLOB C_FILES *.cpp)

# Set the target name and source
add_executable(${PROJECT_NAME} ${C_FILES})
