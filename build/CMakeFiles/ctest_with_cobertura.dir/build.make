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
CMAKE_SOURCE_DIR = /home/p/git/cmocka

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/p/git/cmocka/build

# Utility rule file for ctest_with_cobertura.

# Include the progress variables for this target.
include CMakeFiles/ctest_with_cobertura.dir/progress.make

CMakeFiles/ctest_with_cobertura:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/p/git/cmocka/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running gcovr to produce Cobertura code coverage report."
	ctest --gtest_output=xml:coverage.junit.xml
	/usr/bin/gcovr -x -r /home/p/git/cmocka -o coverage.xml

ctest_with_cobertura: CMakeFiles/ctest_with_cobertura
ctest_with_cobertura: CMakeFiles/ctest_with_cobertura.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Cobertura code coverage report saved in coverage.xml."
.PHONY : ctest_with_cobertura

# Rule to build all files generated by this target.
CMakeFiles/ctest_with_cobertura.dir/build: ctest_with_cobertura

.PHONY : CMakeFiles/ctest_with_cobertura.dir/build

CMakeFiles/ctest_with_cobertura.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ctest_with_cobertura.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ctest_with_cobertura.dir/clean

CMakeFiles/ctest_with_cobertura.dir/depend:
	cd /home/p/git/cmocka/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/p/git/cmocka /home/p/git/cmocka /home/p/git/cmocka/build /home/p/git/cmocka/build /home/p/git/cmocka/build/CMakeFiles/ctest_with_cobertura.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ctest_with_cobertura.dir/depend

