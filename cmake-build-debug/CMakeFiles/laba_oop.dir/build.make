# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gevorgtsaturyan/CLionProjects/laba_oop

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laba_oop.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laba_oop.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba_oop.dir/flags.make

CMakeFiles/laba_oop.dir/main.cpp.o: CMakeFiles/laba_oop.dir/flags.make
CMakeFiles/laba_oop.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laba_oop.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/laba_oop.dir/main.cpp.o -c /Users/gevorgtsaturyan/CLionProjects/laba_oop/main.cpp

CMakeFiles/laba_oop.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laba_oop.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gevorgtsaturyan/CLionProjects/laba_oop/main.cpp > CMakeFiles/laba_oop.dir/main.cpp.i

CMakeFiles/laba_oop.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laba_oop.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gevorgtsaturyan/CLionProjects/laba_oop/main.cpp -o CMakeFiles/laba_oop.dir/main.cpp.s

CMakeFiles/laba_oop.dir/Car.cpp.o: CMakeFiles/laba_oop.dir/flags.make
CMakeFiles/laba_oop.dir/Car.cpp.o: ../Car.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/laba_oop.dir/Car.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/laba_oop.dir/Car.cpp.o -c /Users/gevorgtsaturyan/CLionProjects/laba_oop/Car.cpp

CMakeFiles/laba_oop.dir/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laba_oop.dir/Car.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gevorgtsaturyan/CLionProjects/laba_oop/Car.cpp > CMakeFiles/laba_oop.dir/Car.cpp.i

CMakeFiles/laba_oop.dir/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laba_oop.dir/Car.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gevorgtsaturyan/CLionProjects/laba_oop/Car.cpp -o CMakeFiles/laba_oop.dir/Car.cpp.s

# Object files for target laba_oop
laba_oop_OBJECTS = \
"CMakeFiles/laba_oop.dir/main.cpp.o" \
"CMakeFiles/laba_oop.dir/Car.cpp.o"

# External object files for target laba_oop
laba_oop_EXTERNAL_OBJECTS =

laba_oop: CMakeFiles/laba_oop.dir/main.cpp.o
laba_oop: CMakeFiles/laba_oop.dir/Car.cpp.o
laba_oop: CMakeFiles/laba_oop.dir/build.make
laba_oop: CMakeFiles/laba_oop.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable laba_oop"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/laba_oop.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba_oop.dir/build: laba_oop

.PHONY : CMakeFiles/laba_oop.dir/build

CMakeFiles/laba_oop.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/laba_oop.dir/cmake_clean.cmake
.PHONY : CMakeFiles/laba_oop.dir/clean

CMakeFiles/laba_oop.dir/depend:
	cd /Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gevorgtsaturyan/CLionProjects/laba_oop /Users/gevorgtsaturyan/CLionProjects/laba_oop /Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug /Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug /Users/gevorgtsaturyan/CLionProjects/laba_oop/cmake-build-debug/CMakeFiles/laba_oop.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laba_oop.dir/depend

