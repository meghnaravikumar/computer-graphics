# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release

# Include any dependencies generated for this target.
include CMakeFiles/distances.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/distances.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/distances.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/distances.dir/flags.make

CMakeFiles/distances.dir/distances.cpp.o: CMakeFiles/distances.dir/flags.make
CMakeFiles/distances.dir/distances.cpp.o: /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/distances.cpp
CMakeFiles/distances.dir/distances.cpp.o: CMakeFiles/distances.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/distances.dir/distances.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/distances.dir/distances.cpp.o -MF CMakeFiles/distances.dir/distances.cpp.o.d -o CMakeFiles/distances.dir/distances.cpp.o -c /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/distances.cpp

CMakeFiles/distances.dir/distances.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/distances.dir/distances.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/distances.cpp > CMakeFiles/distances.dir/distances.cpp.i

CMakeFiles/distances.dir/distances.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/distances.dir/distances.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/distances.cpp -o CMakeFiles/distances.dir/distances.cpp.s

# Object files for target distances
distances_OBJECTS = \
"CMakeFiles/distances.dir/distances.cpp.o"

# External object files for target distances
distances_EXTERNAL_OBJECTS =

distances: CMakeFiles/distances.dir/distances.cpp.o
distances: CMakeFiles/distances.dir/build.make
distances: libcore.a
distances: /Library/Developer/CommandLineTools/SDKs/MacOSX11.1.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
distances: glad/libglad.a
distances: glfw/src/libglfw3.a
distances: CMakeFiles/distances.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable distances"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/distances.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/distances.dir/build: distances
.PHONY : CMakeFiles/distances.dir/build

CMakeFiles/distances.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/distances.dir/cmake_clean.cmake
.PHONY : CMakeFiles/distances.dir/clean

CMakeFiles/distances.dir/depend:
	cd /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release /Users/meghna/csc317/computer-graphics-bounding-volume-hierarchy/build-release/CMakeFiles/distances.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/distances.dir/depend

