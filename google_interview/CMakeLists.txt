cmake_minimum_required(VERSION 3.5)
project(google_interview) # Project name
set(CMAKE_CXX_FLAGS "-Wextra -Wall -Werror -pedantic -std=c++11") # Compilation flags

# Set the target name and source
add_executable(${PROJECT_NAME} main.c)
