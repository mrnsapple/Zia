#project(zia-libraries)

#add_library(SSL_Module SHARED SSLModule.cpp)
#set_target_properties(SSL_Module PROPERTIES PUBLIC_HEADER SSLModule.hpp)



############
cmake_minimum_required(VERSION 3.9)

set(NAME SSL_Module)

project(${NAME})
add_definitions("-shared")
add_definitions("-fPIC")
add_definitions("-W -Wall -Wextra")
#find_package(OpenSSL REQUIRED)
#add_definitions("-lssl -lcrypto -ldl")
#add_definitions("-L/usr/lib")

set(SOURCES
	SSLModule.cpp
	SSLModule.hpp
)

#conan_basic_setup()

add_library(${NAME} SHARED ${SOURCES})
target_link_libraries(${NAME} ssl crypto ${CONAN_LIBS})
#set_target_properties(${NAME} PROPERTIES PUBLIC_HEADER SSLModule.hpp)

target_include_directories(${NAME} PUBLIC ../../api/include/)