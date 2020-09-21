cmake_minimum_required(VERSION 3.9)

set(NAME response_module)

project(${NAME})
add_definitions("-shared")
add_definitions("-fPIC")
add_definitions("-W -Wall -Wextra")

set(SOURCES
	ResponseModule.cpp
	ResponseModule.hpp


)

add_library(${NAME} SHARED ${SOURCES})
target_link_libraries(${NAME} stdc++fs)
target_include_directories(${NAME} PUBLIC ../../api/include/)