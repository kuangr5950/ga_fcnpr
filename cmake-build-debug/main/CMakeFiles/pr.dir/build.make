# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = "F:\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\fcnpr\ga_fcnpr\ga_fcnpr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug

# Include any dependencies generated for this target.
include main/CMakeFiles/pr.dir/depend.make

# Include the progress variables for this target.
include main/CMakeFiles/pr.dir/progress.make

# Include the compile flags for this target's objects.
include main/CMakeFiles/pr.dir/flags.make

main/CMakeFiles/pr.dir/main.cpp.obj: main/CMakeFiles/pr.dir/flags.make
main/CMakeFiles/pr.dir/main.cpp.obj: main/CMakeFiles/pr.dir/includes_CXX.rsp
main/CMakeFiles/pr.dir/main.cpp.obj: ../main/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object main/CMakeFiles/pr.dir/main.cpp.obj"
	cd /d D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main && F:\msys64\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\pr.dir\main.cpp.obj -c D:\fcnpr\ga_fcnpr\ga_fcnpr\main\main.cpp

main/CMakeFiles/pr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pr.dir/main.cpp.i"
	cd /d D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main && F:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\fcnpr\ga_fcnpr\ga_fcnpr\main\main.cpp > CMakeFiles\pr.dir\main.cpp.i

main/CMakeFiles/pr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pr.dir/main.cpp.s"
	cd /d D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main && F:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\fcnpr\ga_fcnpr\ga_fcnpr\main\main.cpp -o CMakeFiles\pr.dir\main.cpp.s

# Object files for target pr
pr_OBJECTS = \
"CMakeFiles/pr.dir/main.cpp.obj"

# External object files for target pr
pr_EXTERNAL_OBJECTS =

test/pr.exe: main/CMakeFiles/pr.dir/main.cpp.obj
test/pr.exe: main/CMakeFiles/pr.dir/build.make
test/pr.exe: test/libfcnpr.dll.a
test/pr.exe: lib/mockturtle/lib/abcsat/liblibabcsat.a
test/pr.exe: main/CMakeFiles/pr.dir/linklibs.rsp
test/pr.exe: main/CMakeFiles/pr.dir/objects1.rsp
test/pr.exe: main/CMakeFiles/pr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ..\test\pr.exe"
	cd /d D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\pr.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
main/CMakeFiles/pr.dir/build: test/pr.exe

.PHONY : main/CMakeFiles/pr.dir/build

main/CMakeFiles/pr.dir/clean:
	cd /d D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main && $(CMAKE_COMMAND) -P CMakeFiles\pr.dir\cmake_clean.cmake
.PHONY : main/CMakeFiles/pr.dir/clean

main/CMakeFiles/pr.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\fcnpr\ga_fcnpr\ga_fcnpr D:\fcnpr\ga_fcnpr\ga_fcnpr\main D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main D:\fcnpr\ga_fcnpr\ga_fcnpr\cmake-build-debug\main\CMakeFiles\pr.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : main/CMakeFiles/pr.dir/depend
