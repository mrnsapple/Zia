# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build

# Include any dependencies generated for this target.
include CMakeFiles/zia.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/zia.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zia.dir/flags.make

CMakeFiles/zia.dir/src/main_server.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/src/main_server.cpp.o: ../src/main_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/zia.dir/src/main_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/src/main_server.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/main_server.cpp

CMakeFiles/zia.dir/src/main_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/src/main_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/main_server.cpp > CMakeFiles/zia.dir/src/main_server.cpp.i

CMakeFiles/zia.dir/src/main_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/src/main_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/main_server.cpp -o CMakeFiles/zia.dir/src/main_server.cpp.s

CMakeFiles/zia.dir/src/main_server.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/src/main_server.cpp.o.requires

CMakeFiles/zia.dir/src/main_server.cpp.o.provides: CMakeFiles/zia.dir/src/main_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/src/main_server.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/src/main_server.cpp.o.provides

CMakeFiles/zia.dir/src/main_server.cpp.o.provides.build: CMakeFiles/zia.dir/src/main_server.cpp.o


CMakeFiles/zia.dir/src/server.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/src/server.cpp.o: ../src/server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/zia.dir/src/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/src/server.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/server.cpp

CMakeFiles/zia.dir/src/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/src/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/server.cpp > CMakeFiles/zia.dir/src/server.cpp.i

CMakeFiles/zia.dir/src/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/src/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/server.cpp -o CMakeFiles/zia.dir/src/server.cpp.s

CMakeFiles/zia.dir/src/server.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/src/server.cpp.o.requires

CMakeFiles/zia.dir/src/server.cpp.o.provides: CMakeFiles/zia.dir/src/server.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/src/server.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/src/server.cpp.o.provides

CMakeFiles/zia.dir/src/server.cpp.o.provides.build: CMakeFiles/zia.dir/src/server.cpp.o


CMakeFiles/zia.dir/src/session.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/src/session.cpp.o: ../src/session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/zia.dir/src/session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/src/session.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/session.cpp

CMakeFiles/zia.dir/src/session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/src/session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/session.cpp > CMakeFiles/zia.dir/src/session.cpp.i

CMakeFiles/zia.dir/src/session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/src/session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/session.cpp -o CMakeFiles/zia.dir/src/session.cpp.s

CMakeFiles/zia.dir/src/session.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/src/session.cpp.o.requires

CMakeFiles/zia.dir/src/session.cpp.o.provides: CMakeFiles/zia.dir/src/session.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/src/session.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/src/session.cpp.o.provides

CMakeFiles/zia.dir/src/session.cpp.o.provides.build: CMakeFiles/zia.dir/src/session.cpp.o


CMakeFiles/zia.dir/src/socket.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/src/socket.cpp.o: ../src/socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/zia.dir/src/socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/src/socket.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/socket.cpp

CMakeFiles/zia.dir/src/socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/src/socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/socket.cpp > CMakeFiles/zia.dir/src/socket.cpp.i

CMakeFiles/zia.dir/src/socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/src/socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/socket.cpp -o CMakeFiles/zia.dir/src/socket.cpp.s

CMakeFiles/zia.dir/src/socket.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/src/socket.cpp.o.requires

CMakeFiles/zia.dir/src/socket.cpp.o.provides: CMakeFiles/zia.dir/src/socket.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/src/socket.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/src/socket.cpp.o.provides

CMakeFiles/zia.dir/src/socket.cpp.o.provides.build: CMakeFiles/zia.dir/src/socket.cpp.o


CMakeFiles/zia.dir/src/configuration.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/src/configuration.cpp.o: ../src/configuration.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/zia.dir/src/configuration.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/src/configuration.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/configuration.cpp

CMakeFiles/zia.dir/src/configuration.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/src/configuration.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/configuration.cpp > CMakeFiles/zia.dir/src/configuration.cpp.i

CMakeFiles/zia.dir/src/configuration.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/src/configuration.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/src/configuration.cpp -o CMakeFiles/zia.dir/src/configuration.cpp.s

CMakeFiles/zia.dir/src/configuration.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/src/configuration.cpp.o.requires

CMakeFiles/zia.dir/src/configuration.cpp.o.provides: CMakeFiles/zia.dir/src/configuration.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/src/configuration.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/src/configuration.cpp.o.provides

CMakeFiles/zia.dir/src/configuration.cpp.o.provides.build: CMakeFiles/zia.dir/src/configuration.cpp.o


CMakeFiles/zia.dir/api/src/Hooks.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/api/src/Hooks.cpp.o: ../api/src/Hooks.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/zia.dir/api/src/Hooks.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/api/src/Hooks.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/Hooks.cpp

CMakeFiles/zia.dir/api/src/Hooks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/api/src/Hooks.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/Hooks.cpp > CMakeFiles/zia.dir/api/src/Hooks.cpp.i

CMakeFiles/zia.dir/api/src/Hooks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/api/src/Hooks.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/Hooks.cpp -o CMakeFiles/zia.dir/api/src/Hooks.cpp.s

CMakeFiles/zia.dir/api/src/Hooks.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/api/src/Hooks.cpp.o.requires

CMakeFiles/zia.dir/api/src/Hooks.cpp.o.provides: CMakeFiles/zia.dir/api/src/Hooks.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/api/src/Hooks.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/api/src/Hooks.cpp.o.provides

CMakeFiles/zia.dir/api/src/Hooks.cpp.o.provides.build: CMakeFiles/zia.dir/api/src/Hooks.cpp.o


CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o: ../api/src/HTTPStatus.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/HTTPStatus.cpp

CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/HTTPStatus.cpp > CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.i

CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/HTTPStatus.cpp -o CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.s

CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.requires

CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.provides: CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.provides

CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.provides.build: CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o


CMakeFiles/zia.dir/api/src/Request.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/api/src/Request.cpp.o: ../api/src/Request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/zia.dir/api/src/Request.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/api/src/Request.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/Request.cpp

CMakeFiles/zia.dir/api/src/Request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/api/src/Request.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/Request.cpp > CMakeFiles/zia.dir/api/src/Request.cpp.i

CMakeFiles/zia.dir/api/src/Request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/api/src/Request.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/Request.cpp -o CMakeFiles/zia.dir/api/src/Request.cpp.s

CMakeFiles/zia.dir/api/src/Request.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/api/src/Request.cpp.o.requires

CMakeFiles/zia.dir/api/src/Request.cpp.o.provides: CMakeFiles/zia.dir/api/src/Request.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/api/src/Request.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/api/src/Request.cpp.o.provides

CMakeFiles/zia.dir/api/src/Request.cpp.o.provides.build: CMakeFiles/zia.dir/api/src/Request.cpp.o


CMakeFiles/zia.dir/api/src/RequestManager.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/api/src/RequestManager.cpp.o: ../api/src/RequestManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/zia.dir/api/src/RequestManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/api/src/RequestManager.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/RequestManager.cpp

CMakeFiles/zia.dir/api/src/RequestManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/api/src/RequestManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/RequestManager.cpp > CMakeFiles/zia.dir/api/src/RequestManager.cpp.i

CMakeFiles/zia.dir/api/src/RequestManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/api/src/RequestManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/RequestManager.cpp -o CMakeFiles/zia.dir/api/src/RequestManager.cpp.s

CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.requires

CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.provides: CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.provides

CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.provides.build: CMakeFiles/zia.dir/api/src/RequestManager.cpp.o


CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o: CMakeFiles/zia.dir/flags.make
CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o: ../api/src/ModuleManager.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o -c /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/ModuleManager.cpp

CMakeFiles/zia.dir/api/src/ModuleManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/zia.dir/api/src/ModuleManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/ModuleManager.cpp > CMakeFiles/zia.dir/api/src/ModuleManager.cpp.i

CMakeFiles/zia.dir/api/src/ModuleManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/zia.dir/api/src/ModuleManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/api/src/ModuleManager.cpp -o CMakeFiles/zia.dir/api/src/ModuleManager.cpp.s

CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.requires:

.PHONY : CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.requires

CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.provides: CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.requires
	$(MAKE) -f CMakeFiles/zia.dir/build.make CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.provides.build
.PHONY : CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.provides

CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.provides.build: CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o


# Object files for target zia
zia_OBJECTS = \
"CMakeFiles/zia.dir/src/main_server.cpp.o" \
"CMakeFiles/zia.dir/src/server.cpp.o" \
"CMakeFiles/zia.dir/src/session.cpp.o" \
"CMakeFiles/zia.dir/src/socket.cpp.o" \
"CMakeFiles/zia.dir/src/configuration.cpp.o" \
"CMakeFiles/zia.dir/api/src/Hooks.cpp.o" \
"CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o" \
"CMakeFiles/zia.dir/api/src/Request.cpp.o" \
"CMakeFiles/zia.dir/api/src/RequestManager.cpp.o" \
"CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o"

# External object files for target zia
zia_EXTERNAL_OBJECTS =

bin/zia: CMakeFiles/zia.dir/src/main_server.cpp.o
bin/zia: CMakeFiles/zia.dir/src/server.cpp.o
bin/zia: CMakeFiles/zia.dir/src/session.cpp.o
bin/zia: CMakeFiles/zia.dir/src/socket.cpp.o
bin/zia: CMakeFiles/zia.dir/src/configuration.cpp.o
bin/zia: CMakeFiles/zia.dir/api/src/Hooks.cpp.o
bin/zia: CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o
bin/zia: CMakeFiles/zia.dir/api/src/Request.cpp.o
bin/zia: CMakeFiles/zia.dir/api/src/RequestManager.cpp.o
bin/zia: CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o
bin/zia: CMakeFiles/zia.dir/build.make
bin/zia: CMakeFiles/zia.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable bin/zia"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/zia.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zia.dir/build: bin/zia

.PHONY : CMakeFiles/zia.dir/build

CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/src/main_server.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/src/server.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/src/session.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/src/socket.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/src/configuration.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/api/src/Hooks.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/api/src/HTTPStatus.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/api/src/Request.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/api/src/RequestManager.cpp.o.requires
CMakeFiles/zia.dir/requires: CMakeFiles/zia.dir/api/src/ModuleManager.cpp.o.requires

.PHONY : CMakeFiles/zia.dir/requires

CMakeFiles/zia.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/zia.dir/cmake_clean.cmake
.PHONY : CMakeFiles/zia.dir/clean

CMakeFiles/zia.dir/depend:
	cd /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019 /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019 /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build /home/oriol/Epitech_projects/2_C++/zia/CPP_zia_2019/build/CMakeFiles/zia.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/zia.dir/depend

