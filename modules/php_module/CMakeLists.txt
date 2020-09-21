cmake_minimum_required(VERSION 3.9)

set(NAME php_module)

project(${NAME})
add_definitions("-shared")
add_definitions("-fPIC")
add_definitions("-W -Wall -Wextra")

set(SOURCES
	PhpModule.cpp
	PhpModule.hpp
	../../include/configuration.hpp
	../../src/configuration.cpp


)

add_library(${NAME} SHARED ${SOURCES})
target_link_libraries(${NAME} stdc++fs)
target_include_directories(${NAME} PUBLIC ../../api/include/)