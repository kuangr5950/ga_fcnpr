# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\msys2\mingw64\bin\cmake.exe

# The command to remove a file.
RM = D:\msys2\mingw64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\user\Desktop\ga_fcnpr (1)"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\user\Desktop\ga_fcnpr (1)\cmake-build-debug"

# Include any dependencies generated for this target.
include test/CMakeFiles/PandRGATest.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/PandRGATest.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/PandRGATest.dir/flags.make

test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.obj: test/CMakeFiles/PandRGATest.dir/flags.make
test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.obj: test/CMakeFiles/PandRGATest.dir/includes_CXX.rsp
test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.obj: ../test/PandR_GATest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\user\Desktop\ga_fcnpr (1)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.obj"
	cd /d C:\Users\user\Desktop\GA_FCN~1\CMAKE-~1\test && D:\msys2\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\PandRGATest.dir\PandR_GATest.cpp.obj -c "C:\Users\user\Desktop\ga_fcnpr (1)\test\PandR_GATest.cpp"

test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.i"
	cd /d C:\Users\user\Desktop\GA_FCN~1\CMAKE-~1\test && D:\msys2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\user\Desktop\ga_fcnpr (1)\test\PandR_GATest.cpp" > CMakeFiles\PandRGATest.dir\PandR_GATest.cpp.i

test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.s"
	cd /d C:\Users\user\Desktop\GA_FCN~1\CMAKE-~1\test && D:\msys2\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\user\Desktop\ga_fcnpr (1)\test\PandR_GATest.cpp" -o CMakeFiles\PandRGATest.dir\PandR_GATest.cpp.s

# Object files for target PandRGATest
PandRGATest_OBJECTS = \
"CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.obj"

# External object files for target PandRGATest
PandRGATest_EXTERNAL_OBJECTS =

test/PandRGATest.exe: test/CMakeFiles/PandRGATest.dir/PandR_GATest.cpp.obj
test/PandRGATest.exe: test/CMakeFiles/PandRGATest.dir/build.make
test/PandRGATest.exe: test/libfcnpr.dll.a
test/PandRGATest.exe: lib/mockturtle/lib/abcsat/liblibabcsat.a
test/PandRGATest.exe: test/CMakeFiles/PandRGATest.dir/linklibs.rsp
test/PandRGATest.exe: test/CMakeFiles/PandRGATest.dir/objects1.rsp
test/PandRGATest.exe: test/CMakeFiles/PandRGATest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\user\Desktop\ga_fcnpr (1)\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PandRGATest.exe"
	cd /d C:\Users\user\Desktop\GA_FCN~1\CMAKE-~1\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\PandRGATest.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/PandRGATest.dir/build: test/PandRGATest.exe

.PHONY : test/CMakeFiles/PandRGATest.dir/build

test/CMakeFiles/PandRGATest.dir/clean:
	cd /d C:\Users\user\Desktop\GA_FCN~1\CMAKE-~1\test && $(CMAKE_COMMAND) -P CMakeFiles\PandRGATest.dir\cmake_clean.cmake
.PHONY : test/CMakeFiles/PandRGATest.dir/clean

test/CMakeFiles/PandRGATest.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\user\Desktop\ga_fcnpr (1)" "C:\Users\user\Desktop\ga_fcnpr (1)\test" "C:\Users\user\Desktop\ga_fcnpr (1)\cmake-build-debug" "C:\Users\user\Desktop\ga_fcnpr (1)\cmake-build-debug\test" "C:\Users\user\Desktop\ga_fcnpr (1)\cmake-build-debug\test\CMakeFiles\PandRGATest.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : test/CMakeFiles/PandRGATest.dir/depend

