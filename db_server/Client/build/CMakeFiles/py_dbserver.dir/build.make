# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ase/Syng_og_Sammenlign/db_server/Client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ase/Syng_og_Sammenlign/db_server/Client/build

# Include any dependencies generated for this target.
include CMakeFiles/py_dbserver.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/py_dbserver.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/py_dbserver.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/py_dbserver.dir/flags.make

CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o: CMakeFiles/py_dbserver.dir/flags.make
CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o: ../py_dbserver.cpp
CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o: CMakeFiles/py_dbserver.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ase/Syng_og_Sammenlign/db_server/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o -MF CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o.d -o CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o -c /home/ase/Syng_og_Sammenlign/db_server/Client/py_dbserver.cpp

CMakeFiles/py_dbserver.dir/py_dbserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/py_dbserver.dir/py_dbserver.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ase/Syng_og_Sammenlign/db_server/Client/py_dbserver.cpp > CMakeFiles/py_dbserver.dir/py_dbserver.cpp.i

CMakeFiles/py_dbserver.dir/py_dbserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/py_dbserver.dir/py_dbserver.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ase/Syng_og_Sammenlign/db_server/Client/py_dbserver.cpp -o CMakeFiles/py_dbserver.dir/py_dbserver.cpp.s

# Object files for target py_dbserver
py_dbserver_OBJECTS = \
"CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o"

# External object files for target py_dbserver
py_dbserver_EXTERNAL_OBJECTS =

py_dbserver.cpython-310-x86_64-linux-gnu.so: CMakeFiles/py_dbserver.dir/py_dbserver.cpp.o
py_dbserver.cpython-310-x86_64-linux-gnu.so: CMakeFiles/py_dbserver.dir/build.make
py_dbserver.cpython-310-x86_64-linux-gnu.so: CMakeFiles/py_dbserver.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ase/Syng_og_Sammenlign/db_server/Client/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared module py_dbserver.cpython-310-x86_64-linux-gnu.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/py_dbserver.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/py_dbserver.dir/build: py_dbserver.cpython-310-x86_64-linux-gnu.so
.PHONY : CMakeFiles/py_dbserver.dir/build

CMakeFiles/py_dbserver.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/py_dbserver.dir/cmake_clean.cmake
.PHONY : CMakeFiles/py_dbserver.dir/clean

CMakeFiles/py_dbserver.dir/depend:
	cd /home/ase/Syng_og_Sammenlign/db_server/Client/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ase/Syng_og_Sammenlign/db_server/Client /home/ase/Syng_og_Sammenlign/db_server/Client /home/ase/Syng_og_Sammenlign/db_server/Client/build /home/ase/Syng_og_Sammenlign/db_server/Client/build /home/ase/Syng_og_Sammenlign/db_server/Client/build/CMakeFiles/py_dbserver.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/py_dbserver.dir/depend

