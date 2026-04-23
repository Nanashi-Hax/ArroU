cmake_minimum_required(VERSION 3.13)
project(ArroU CXX)

set(DIST_DIR "${CMAKE_SOURCE_DIR}/Dist/${PLATFORM}")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(Source)
