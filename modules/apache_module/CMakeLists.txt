cmake_minimum_required(VERSION 3.9)

set(NAME apache_module)

project(${NAME})
add_definitions("-shared")
add_definitions("-fPIC")
add_definitions("-W -Wall -Wextra")

set(SOURCES
	ApacheModule.cpp
	ApacheModule.hpp
)

add_library(${NAME} SHARED ${SOURCES})
target_link_libraries(${NAME} stdc++fs)
target_include_directories(${NAME} PUBLIC  ../../api/include/)