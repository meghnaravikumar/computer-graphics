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
CMAKE_SOURCE_DIR = /Users/meghna/csc317/computer-graphics-meshes

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/meghna/csc317/computer-graphics-meshes/build-release

# Include any dependencies generated for this target.
include CMakeFiles/core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/core.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/core.dir/flags.make

CMakeFiles/core.dir/src/catmull_clark.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/catmull_clark.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/catmull_clark.cpp
CMakeFiles/core.dir/src/catmull_clark.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/core.dir/src/catmull_clark.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/catmull_clark.cpp.o -MF CMakeFiles/core.dir/src/catmull_clark.cpp.o.d -o CMakeFiles/core.dir/src/catmull_clark.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/catmull_clark.cpp

CMakeFiles/core.dir/src/catmull_clark.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/catmull_clark.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/catmull_clark.cpp > CMakeFiles/core.dir/src/catmull_clark.cpp.i

CMakeFiles/core.dir/src/catmull_clark.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/catmull_clark.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/catmull_clark.cpp -o CMakeFiles/core.dir/src/catmull_clark.cpp.s

CMakeFiles/core.dir/src/cube.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/cube.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/cube.cpp
CMakeFiles/core.dir/src/cube.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/core.dir/src/cube.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/cube.cpp.o -MF CMakeFiles/core.dir/src/cube.cpp.o.d -o CMakeFiles/core.dir/src/cube.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/cube.cpp

CMakeFiles/core.dir/src/cube.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/cube.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/cube.cpp > CMakeFiles/core.dir/src/cube.cpp.i

CMakeFiles/core.dir/src/cube.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/cube.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/cube.cpp -o CMakeFiles/core.dir/src/cube.cpp.s

CMakeFiles/core.dir/src/per_corner_normals.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/per_corner_normals.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/per_corner_normals.cpp
CMakeFiles/core.dir/src/per_corner_normals.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/core.dir/src/per_corner_normals.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/per_corner_normals.cpp.o -MF CMakeFiles/core.dir/src/per_corner_normals.cpp.o.d -o CMakeFiles/core.dir/src/per_corner_normals.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/per_corner_normals.cpp

CMakeFiles/core.dir/src/per_corner_normals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/per_corner_normals.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/per_corner_normals.cpp > CMakeFiles/core.dir/src/per_corner_normals.cpp.i

CMakeFiles/core.dir/src/per_corner_normals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/per_corner_normals.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/per_corner_normals.cpp -o CMakeFiles/core.dir/src/per_corner_normals.cpp.s

CMakeFiles/core.dir/src/per_face_normals.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/per_face_normals.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/per_face_normals.cpp
CMakeFiles/core.dir/src/per_face_normals.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/core.dir/src/per_face_normals.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/per_face_normals.cpp.o -MF CMakeFiles/core.dir/src/per_face_normals.cpp.o.d -o CMakeFiles/core.dir/src/per_face_normals.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/per_face_normals.cpp

CMakeFiles/core.dir/src/per_face_normals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/per_face_normals.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/per_face_normals.cpp > CMakeFiles/core.dir/src/per_face_normals.cpp.i

CMakeFiles/core.dir/src/per_face_normals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/per_face_normals.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/per_face_normals.cpp -o CMakeFiles/core.dir/src/per_face_normals.cpp.s

CMakeFiles/core.dir/src/per_vertex_normals.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/per_vertex_normals.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/per_vertex_normals.cpp
CMakeFiles/core.dir/src/per_vertex_normals.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/core.dir/src/per_vertex_normals.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/per_vertex_normals.cpp.o -MF CMakeFiles/core.dir/src/per_vertex_normals.cpp.o.d -o CMakeFiles/core.dir/src/per_vertex_normals.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/per_vertex_normals.cpp

CMakeFiles/core.dir/src/per_vertex_normals.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/per_vertex_normals.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/per_vertex_normals.cpp > CMakeFiles/core.dir/src/per_vertex_normals.cpp.i

CMakeFiles/core.dir/src/per_vertex_normals.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/per_vertex_normals.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/per_vertex_normals.cpp -o CMakeFiles/core.dir/src/per_vertex_normals.cpp.s

CMakeFiles/core.dir/src/sphere.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/sphere.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/sphere.cpp
CMakeFiles/core.dir/src/sphere.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/core.dir/src/sphere.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/sphere.cpp.o -MF CMakeFiles/core.dir/src/sphere.cpp.o.d -o CMakeFiles/core.dir/src/sphere.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/sphere.cpp

CMakeFiles/core.dir/src/sphere.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/sphere.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/sphere.cpp > CMakeFiles/core.dir/src/sphere.cpp.i

CMakeFiles/core.dir/src/sphere.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/sphere.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/sphere.cpp -o CMakeFiles/core.dir/src/sphere.cpp.s

CMakeFiles/core.dir/src/triangle_area_normal.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/triangle_area_normal.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/triangle_area_normal.cpp
CMakeFiles/core.dir/src/triangle_area_normal.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/core.dir/src/triangle_area_normal.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/triangle_area_normal.cpp.o -MF CMakeFiles/core.dir/src/triangle_area_normal.cpp.o.d -o CMakeFiles/core.dir/src/triangle_area_normal.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/triangle_area_normal.cpp

CMakeFiles/core.dir/src/triangle_area_normal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/triangle_area_normal.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/triangle_area_normal.cpp > CMakeFiles/core.dir/src/triangle_area_normal.cpp.i

CMakeFiles/core.dir/src/triangle_area_normal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/triangle_area_normal.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/triangle_area_normal.cpp -o CMakeFiles/core.dir/src/triangle_area_normal.cpp.s

CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/vertex_triangle_adjacency.cpp
CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o -MF CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o.d -o CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/vertex_triangle_adjacency.cpp

CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/vertex_triangle_adjacency.cpp > CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.i

CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/vertex_triangle_adjacency.cpp -o CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.s

CMakeFiles/core.dir/src/write_obj.cpp.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/write_obj.cpp.o: /Users/meghna/csc317/computer-graphics-meshes/src/write_obj.cpp
CMakeFiles/core.dir/src/write_obj.cpp.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/core.dir/src/write_obj.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/core.dir/src/write_obj.cpp.o -MF CMakeFiles/core.dir/src/write_obj.cpp.o.d -o CMakeFiles/core.dir/src/write_obj.cpp.o -c /Users/meghna/csc317/computer-graphics-meshes/src/write_obj.cpp

CMakeFiles/core.dir/src/write_obj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/core.dir/src/write_obj.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/meghna/csc317/computer-graphics-meshes/src/write_obj.cpp > CMakeFiles/core.dir/src/write_obj.cpp.i

CMakeFiles/core.dir/src/write_obj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/core.dir/src/write_obj.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/meghna/csc317/computer-graphics-meshes/src/write_obj.cpp -o CMakeFiles/core.dir/src/write_obj.cpp.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/src/catmull_clark.cpp.o" \
"CMakeFiles/core.dir/src/cube.cpp.o" \
"CMakeFiles/core.dir/src/per_corner_normals.cpp.o" \
"CMakeFiles/core.dir/src/per_face_normals.cpp.o" \
"CMakeFiles/core.dir/src/per_vertex_normals.cpp.o" \
"CMakeFiles/core.dir/src/sphere.cpp.o" \
"CMakeFiles/core.dir/src/triangle_area_normal.cpp.o" \
"CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o" \
"CMakeFiles/core.dir/src/write_obj.cpp.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

libcore.a: CMakeFiles/core.dir/src/catmull_clark.cpp.o
libcore.a: CMakeFiles/core.dir/src/cube.cpp.o
libcore.a: CMakeFiles/core.dir/src/per_corner_normals.cpp.o
libcore.a: CMakeFiles/core.dir/src/per_face_normals.cpp.o
libcore.a: CMakeFiles/core.dir/src/per_vertex_normals.cpp.o
libcore.a: CMakeFiles/core.dir/src/sphere.cpp.o
libcore.a: CMakeFiles/core.dir/src/triangle_area_normal.cpp.o
libcore.a: CMakeFiles/core.dir/src/vertex_triangle_adjacency.cpp.o
libcore.a: CMakeFiles/core.dir/src/write_obj.cpp.o
libcore.a: CMakeFiles/core.dir/build.make
libcore.a: CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX static library libcore.a"
	$(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/core.dir/build: libcore.a
.PHONY : CMakeFiles/core.dir/build

CMakeFiles/core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/core.dir/clean

CMakeFiles/core.dir/depend:
	cd /Users/meghna/csc317/computer-graphics-meshes/build-release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/meghna/csc317/computer-graphics-meshes /Users/meghna/csc317/computer-graphics-meshes /Users/meghna/csc317/computer-graphics-meshes/build-release /Users/meghna/csc317/computer-graphics-meshes/build-release /Users/meghna/csc317/computer-graphics-meshes/build-release/CMakeFiles/core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/core.dir/depend

