##
## EPITECH PROJECT, 2021
## follow up colle
## File description:
## CMakeLists.txt
##

# Header
cmake_minimum_required(VERSION 3.0)
project(tail)

# Compiler options
if (CMAKE_COMPILER_IS_GNUCC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra")
endif()

# Includes
include_directories(include)

# Sources
file(GLOB_RECURSE SRC include/*.h src/*.c)

# Executable
add_executable(${PROJECT_NAME} ${SRC})