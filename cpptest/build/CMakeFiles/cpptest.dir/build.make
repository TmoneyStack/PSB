# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/todzi/psp/cpptest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/todzi/psp/cpptest/build

# Include any dependencies generated for this target.
include CMakeFiles/cpptest.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cpptest.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cpptest.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cpptest.dir/flags.make

CMakeFiles/cpptest.dir/main.cpp.obj: CMakeFiles/cpptest.dir/flags.make
CMakeFiles/cpptest.dir/main.cpp.obj: /home/todzi/psp/cpptest/main.cpp
CMakeFiles/cpptest.dir/main.cpp.obj: CMakeFiles/cpptest.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/todzi/psp/cpptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cpptest.dir/main.cpp.obj"
	/home/todzi/pspdev/bin/psp-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cpptest.dir/main.cpp.obj -MF CMakeFiles/cpptest.dir/main.cpp.obj.d -o CMakeFiles/cpptest.dir/main.cpp.obj -c /home/todzi/psp/cpptest/main.cpp

CMakeFiles/cpptest.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cpptest.dir/main.cpp.i"
	/home/todzi/pspdev/bin/psp-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/todzi/psp/cpptest/main.cpp > CMakeFiles/cpptest.dir/main.cpp.i

CMakeFiles/cpptest.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cpptest.dir/main.cpp.s"
	/home/todzi/pspdev/bin/psp-g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/todzi/psp/cpptest/main.cpp -o CMakeFiles/cpptest.dir/main.cpp.s

# Object files for target cpptest
cpptest_OBJECTS = \
"CMakeFiles/cpptest.dir/main.cpp.obj"

# External object files for target cpptest
cpptest_EXTERNAL_OBJECTS = \
"/home/todzi/psp/cpptest/Hitbox.o"

cpptest: CMakeFiles/cpptest.dir/main.cpp.obj
cpptest: /home/todzi/psp/cpptest/Hitbox.o
cpptest: CMakeFiles/cpptest.dir/build.make
cpptest: CMakeFiles/cpptest.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/todzi/psp/cpptest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable cpptest"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cpptest.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -E cmake_echo_color --cyan Not\ stripping\ binary\ for\ target\ cpptest\ because\ building\ PRX.
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling psp-fixup-imports for target cpptest"
	/home/todzi/pspdev/bin/psp-fixup-imports /home/todzi/psp/cpptest/build/cpptest
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling prxgen for target cpptest"
	/home/todzi/pspdev/bin/psp-prxgen /home/todzi/psp/cpptest/build/cpptest /home/todzi/psp/cpptest/build/cpptest.prx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling PrxEncrypter for target cpptest"
	/home/todzi/pspdev/bin/PrxEncrypter /home/todzi/psp/cpptest/build/cpptest.prx /home/todzi/psp/cpptest/build/cpptest.prx
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling mksfoex for target cpptest"
	/home/todzi/pspdev/bin/mksfoex -d MEMSIZE=1 -s APP_VER=01.00 cpptest /home/todzi/psp/cpptest/build/PARAM.SFO
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Calling pack-pbp with PRX file for target cpptest"
	/home/todzi/pspdev/bin/pack-pbp /home/todzi/psp/cpptest/build/EBOOT.PBP /home/todzi/psp/cpptest/build/PARAM.SFO NULL NULL NULL NULL NULL /home/todzi/psp/cpptest/build/cpptest.prx NULL
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold "Cleaning up PARAM.SFO for target cpptest"
	/usr/bin/cmake -E remove /home/todzi/psp/cpptest/build/PARAM.SFO
	/usr/bin/cmake -E cmake_echo_color --cyan EBOOT.PBP\ file\ created\ for\ target\ cpptest.

# Rule to build all files generated by this target.
CMakeFiles/cpptest.dir/build: cpptest
.PHONY : CMakeFiles/cpptest.dir/build

CMakeFiles/cpptest.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cpptest.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cpptest.dir/clean

CMakeFiles/cpptest.dir/depend:
	cd /home/todzi/psp/cpptest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/todzi/psp/cpptest /home/todzi/psp/cpptest /home/todzi/psp/cpptest/build /home/todzi/psp/cpptest/build /home/todzi/psp/cpptest/build/CMakeFiles/cpptest.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cpptest.dir/depend
