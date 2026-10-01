cmake_minimum_required(VERSION 3.15)

project(xtemu CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)
include_directories(src)

set(SOURCES
    src/main.cpp
	src/cpu8088.cpp
	src/core.cpp
)

add_executable(xtemu ${SOURCES})
