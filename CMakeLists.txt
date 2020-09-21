

cmake_minimum_required(VERSION 3.0)
set(CMAKE_CXX_STANDARD 17)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

########################################
#lpthread
project(Zia)
conan_basic_setup()
add_definitions("-fPIC -g3")
add_definitions("-W -Wall -Wextra  -lstdc++fs --std=c++17 -lpthread")

########################################

set(EXEC_NAME zia)

set(SOURCES
	src/main_server.cpp
	src/server.cpp
	src/session.cpp
	src/socket.cpp
	src/configuration.cpp
	include/configuration.hpp
	#src/main.cpp
	include/socket.hpp
	include/server.hpp
	include/session.hpp
	api/include/Export.hpp
	api/include/HTTPStatus.hpp
	api/include/IHooks.hpp
	api/include/Hooks.hpp
	api/src/Hooks.cpp
	api/include/IModule.hpp
	api/include/NetworkDialog.hpp
	api/include/Request.hpp
	api/include/Response.hpp
	api/src/HTTPStatus.cpp
	api/src/Request.cpp
	api/src/RequestManager.cpp
	api/include/RequestManager.hpp
	api/src/ModuleManager.cpp
	api/include/ModuleManager.hpp
)

add_executable(${EXEC_NAME} ${SOURCES})
target_include_directories(${EXEC_NAME} PUBLIC src/)
target_link_libraries(${EXEC_NAME} ${Boost_LIBRARIES} dl pthread stdc++fs)

########################################

add_subdirectory(modules/)
