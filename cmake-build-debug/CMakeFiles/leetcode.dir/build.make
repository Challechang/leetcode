# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.7

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2017.1.3\bin\cmake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Administrator\CLionProjects\git\leetcode

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Administrator\CLionProjects\git\leetcode\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/leetcode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/leetcode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/leetcode.dir/flags.make

CMakeFiles/leetcode.dir/main.cpp.obj: CMakeFiles/leetcode.dir/flags.make
CMakeFiles/leetcode.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Administrator\CLionProjects\git\leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/leetcode.dir/main.cpp.obj"
	D:\MinGW\bin\g++.exe   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\leetcode.dir\main.cpp.obj -c C:\Users\Administrator\CLionProjects\git\leetcode\main.cpp

CMakeFiles/leetcode.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leetcode.dir/main.cpp.i"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Administrator\CLionProjects\git\leetcode\main.cpp > CMakeFiles\leetcode.dir\main.cpp.i

CMakeFiles/leetcode.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leetcode.dir/main.cpp.s"
	D:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Administrator\CLionProjects\git\leetcode\main.cpp -o CMakeFiles\leetcode.dir\main.cpp.s

CMakeFiles/leetcode.dir/main.cpp.obj.requires:

.PHONY : CMakeFiles/leetcode.dir/main.cpp.obj.requires

CMakeFiles/leetcode.dir/main.cpp.obj.provides: CMakeFiles/leetcode.dir/main.cpp.obj.requires
	$(MAKE) -f CMakeFiles\leetcode.dir\build.make CMakeFiles/leetcode.dir/main.cpp.obj.provides.build
.PHONY : CMakeFiles/leetcode.dir/main.cpp.obj.provides

CMakeFiles/leetcode.dir/main.cpp.obj.provides.build: CMakeFiles/leetcode.dir/main.cpp.obj


# Object files for target leetcode
leetcode_OBJECTS = \
"CMakeFiles/leetcode.dir/main.cpp.obj"

# External object files for target leetcode
leetcode_EXTERNAL_OBJECTS =

leetcode.exe: CMakeFiles/leetcode.dir/main.cpp.obj
leetcode.exe: CMakeFiles/leetcode.dir/build.make
leetcode.exe: CMakeFiles/leetcode.dir/linklibs.rsp
leetcode.exe: CMakeFiles/leetcode.dir/objects1.rsp
leetcode.exe: CMakeFiles/leetcode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Administrator\CLionProjects\git\leetcode\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable leetcode.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\leetcode.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/leetcode.dir/build: leetcode.exe

.PHONY : CMakeFiles/leetcode.dir/build

CMakeFiles/leetcode.dir/requires: CMakeFiles/leetcode.dir/main.cpp.obj.requires

.PHONY : CMakeFiles/leetcode.dir/requires

CMakeFiles/leetcode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\leetcode.dir\cmake_clean.cmake
.PHONY : CMakeFiles/leetcode.dir/clean

CMakeFiles/leetcode.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Administrator\CLionProjects\git\leetcode C:\Users\Administrator\CLionProjects\git\leetcode C:\Users\Administrator\CLionProjects\git\leetcode\cmake-build-debug C:\Users\Administrator\CLionProjects\git\leetcode\cmake-build-debug C:\Users\Administrator\CLionProjects\git\leetcode\cmake-build-debug\CMakeFiles\leetcode.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/leetcode.dir/depend

