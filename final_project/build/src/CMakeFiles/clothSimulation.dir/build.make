# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/834/bin/cmake

# The command to remove a file.
RM = /snap/cmake/834/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/maodou/CLionProjects/cs180/final_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/maodou/CLionProjects/cs180/final_project/build

# Include any dependencies generated for this target.
include src/CMakeFiles/clothSimulation.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/clothSimulation.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/clothSimulation.dir/flags.make

src/CMakeFiles/clothSimulation.dir/cloth.cpp.o: src/CMakeFiles/clothSimulation.dir/flags.make
src/CMakeFiles/clothSimulation.dir/cloth.cpp.o: ../src/cloth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maodou/CLionProjects/cs180/final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/clothSimulation.dir/cloth.cpp.o"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clothSimulation.dir/cloth.cpp.o -c /home/maodou/CLionProjects/cs180/final_project/src/cloth.cpp

src/CMakeFiles/clothSimulation.dir/cloth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clothSimulation.dir/cloth.cpp.i"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maodou/CLionProjects/cs180/final_project/src/cloth.cpp > CMakeFiles/clothSimulation.dir/cloth.cpp.i

src/CMakeFiles/clothSimulation.dir/cloth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clothSimulation.dir/cloth.cpp.s"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maodou/CLionProjects/cs180/final_project/src/cloth.cpp -o CMakeFiles/clothSimulation.dir/cloth.cpp.s

src/CMakeFiles/clothSimulation.dir/application.cpp.o: src/CMakeFiles/clothSimulation.dir/flags.make
src/CMakeFiles/clothSimulation.dir/application.cpp.o: ../src/application.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maodou/CLionProjects/cs180/final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/clothSimulation.dir/application.cpp.o"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clothSimulation.dir/application.cpp.o -c /home/maodou/CLionProjects/cs180/final_project/src/application.cpp

src/CMakeFiles/clothSimulation.dir/application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clothSimulation.dir/application.cpp.i"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maodou/CLionProjects/cs180/final_project/src/application.cpp > CMakeFiles/clothSimulation.dir/application.cpp.i

src/CMakeFiles/clothSimulation.dir/application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clothSimulation.dir/application.cpp.s"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maodou/CLionProjects/cs180/final_project/src/application.cpp -o CMakeFiles/clothSimulation.dir/application.cpp.s

src/CMakeFiles/clothSimulation.dir/main.cpp.o: src/CMakeFiles/clothSimulation.dir/flags.make
src/CMakeFiles/clothSimulation.dir/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/maodou/CLionProjects/cs180/final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/CMakeFiles/clothSimulation.dir/main.cpp.o"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/clothSimulation.dir/main.cpp.o -c /home/maodou/CLionProjects/cs180/final_project/src/main.cpp

src/CMakeFiles/clothSimulation.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/clothSimulation.dir/main.cpp.i"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/maodou/CLionProjects/cs180/final_project/src/main.cpp > CMakeFiles/clothSimulation.dir/main.cpp.i

src/CMakeFiles/clothSimulation.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/clothSimulation.dir/main.cpp.s"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/maodou/CLionProjects/cs180/final_project/src/main.cpp -o CMakeFiles/clothSimulation.dir/main.cpp.s

# Object files for target clothSimulation
clothSimulation_OBJECTS = \
"CMakeFiles/clothSimulation.dir/cloth.cpp.o" \
"CMakeFiles/clothSimulation.dir/application.cpp.o" \
"CMakeFiles/clothSimulation.dir/main.cpp.o"

# External object files for target clothSimulation
clothSimulation_EXTERNAL_OBJECTS =

clothSimulation: src/CMakeFiles/clothSimulation.dir/cloth.cpp.o
clothSimulation: src/CMakeFiles/clothSimulation.dir/application.cpp.o
clothSimulation: src/CMakeFiles/clothSimulation.dir/main.cpp.o
clothSimulation: src/CMakeFiles/clothSimulation.dir/build.make
clothSimulation: CGL/src/libCGL.a
clothSimulation: CGL/deps/glew/libglew.a
clothSimulation: CGL/deps/glfw/src/libglfw3.a
clothSimulation: /usr/lib/x86_64-linux-gnu/libX11.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libXrandr.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libXinerama.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libXi.so
clothSimulation: /usr/lib/x86_64-linux-gnu/librt.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libm.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libXcursor.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libGL.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libGL.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libGLU.so
clothSimulation: /usr/lib/x86_64-linux-gnu/libfreetype.so
clothSimulation: src/CMakeFiles/clothSimulation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/maodou/CLionProjects/cs180/final_project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ../clothSimulation"
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clothSimulation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/clothSimulation.dir/build: clothSimulation

.PHONY : src/CMakeFiles/clothSimulation.dir/build

src/CMakeFiles/clothSimulation.dir/clean:
	cd /home/maodou/CLionProjects/cs180/final_project/build/src && $(CMAKE_COMMAND) -P CMakeFiles/clothSimulation.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/clothSimulation.dir/clean

src/CMakeFiles/clothSimulation.dir/depend:
	cd /home/maodou/CLionProjects/cs180/final_project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/maodou/CLionProjects/cs180/final_project /home/maodou/CLionProjects/cs180/final_project/src /home/maodou/CLionProjects/cs180/final_project/build /home/maodou/CLionProjects/cs180/final_project/build/src /home/maodou/CLionProjects/cs180/final_project/build/src/CMakeFiles/clothSimulation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/clothSimulation.dir/depend

