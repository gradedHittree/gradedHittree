# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.8.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.8.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/goroyabu/Soft/gradedHittree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/goroyabu/Soft/gradedHittree/build

# Include any dependencies generated for this target.
include ruby/CMakeFiles/eventTree2HitTreeGen.dir/depend.make

# Include the progress variables for this target.
include ruby/CMakeFiles/eventTree2HitTreeGen.dir/progress.make

# Include the compile flags for this target's objects.
include ruby/CMakeFiles/eventTree2HitTreeGen.dir/flags.make

ruby/eventTree2HitTreeGenRUBY_wrap.cxx: ../ruby/eventTree2HitTreeGen.i
ruby/eventTree2HitTreeGenRUBY_wrap.cxx: ../ruby/eventTree2HitTreeGen.i
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/Users/goroyabu/Soft/gradedHittree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Swig source"
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && /usr/local/Cellar/cmake/3.8.1/bin/cmake -E make_directory /Users/goroyabu/Soft/gradedHittree/build/ruby
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && /usr/local/bin/swig -ruby -outdir /Users/goroyabu/Soft/gradedHittree/build/ruby -c++ -I/Users/goroyabu/Soft/gradedHittree/include -I/Users/goroyabu/include/anl -I/usr/local/include -I/usr/local/Cellar/root/5.34.34_1/include/root -I/Users/goroyabu/Soft/gradedHittree/ruby/../include -I/Users/goroyabu/include/anl/ruby -I/usr/local/Cellar/ruby/2.4.1_1/include/ruby-2.4.0 -I/usr/local/Cellar/ruby/2.4.1_1/include/ruby-2.4.0/x86_64-darwin15 -o /Users/goroyabu/Soft/gradedHittree/build/ruby/eventTree2HitTreeGenRUBY_wrap.cxx /Users/goroyabu/Soft/gradedHittree/ruby/eventTree2HitTreeGen.i

ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o: ruby/CMakeFiles/eventTree2HitTreeGen.dir/flags.make
ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o: ruby/eventTree2HitTreeGenRUBY_wrap.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/goroyabu/Soft/gradedHittree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o"
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o -c /Users/goroyabu/Soft/gradedHittree/build/ruby/eventTree2HitTreeGenRUBY_wrap.cxx

ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.i"
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/goroyabu/Soft/gradedHittree/build/ruby/eventTree2HitTreeGenRUBY_wrap.cxx > CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.i

ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.s"
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/goroyabu/Soft/gradedHittree/build/ruby/eventTree2HitTreeGenRUBY_wrap.cxx -o CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.s

ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.requires:

.PHONY : ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.requires

ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.provides: ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.requires
	$(MAKE) -f ruby/CMakeFiles/eventTree2HitTreeGen.dir/build.make ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.provides.build
.PHONY : ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.provides

ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.provides.build: ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o


# Object files for target eventTree2HitTreeGen
eventTree2HitTreeGen_OBJECTS = \
"CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o"

# External object files for target eventTree2HitTreeGen
eventTree2HitTreeGen_EXTERNAL_OBJECTS =

ruby/eventTree2HitTreeGen.bundle: ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o
ruby/eventTree2HitTreeGen.bundle: ruby/CMakeFiles/eventTree2HitTreeGen.dir/build.make
ruby/eventTree2HitTreeGen.bundle: libEventTree2HitTreeGen.dylib
ruby/eventTree2HitTreeGen.bundle: /usr/local/lib/libboost_system-mt.dylib
ruby/eventTree2HitTreeGen.bundle: /usr/local/lib/libboost_chrono-mt.dylib
ruby/eventTree2HitTreeGen.bundle: /usr/local/lib/libboost_thread-mt.dylib
ruby/eventTree2HitTreeGen.bundle: /usr/local/lib/libboost_date_time-mt.dylib
ruby/eventTree2HitTreeGen.bundle: /usr/local/lib/libboost_atomic-mt.dylib
ruby/eventTree2HitTreeGen.bundle: ruby/CMakeFiles/eventTree2HitTreeGen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/goroyabu/Soft/gradedHittree/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared module eventTree2HitTreeGen.bundle"
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/eventTree2HitTreeGen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ruby/CMakeFiles/eventTree2HitTreeGen.dir/build: ruby/eventTree2HitTreeGen.bundle

.PHONY : ruby/CMakeFiles/eventTree2HitTreeGen.dir/build

ruby/CMakeFiles/eventTree2HitTreeGen.dir/requires: ruby/CMakeFiles/eventTree2HitTreeGen.dir/eventTree2HitTreeGenRUBY_wrap.cxx.o.requires

.PHONY : ruby/CMakeFiles/eventTree2HitTreeGen.dir/requires

ruby/CMakeFiles/eventTree2HitTreeGen.dir/clean:
	cd /Users/goroyabu/Soft/gradedHittree/build/ruby && $(CMAKE_COMMAND) -P CMakeFiles/eventTree2HitTreeGen.dir/cmake_clean.cmake
.PHONY : ruby/CMakeFiles/eventTree2HitTreeGen.dir/clean

ruby/CMakeFiles/eventTree2HitTreeGen.dir/depend: ruby/eventTree2HitTreeGenRUBY_wrap.cxx
	cd /Users/goroyabu/Soft/gradedHittree/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/goroyabu/Soft/gradedHittree /Users/goroyabu/Soft/gradedHittree/ruby /Users/goroyabu/Soft/gradedHittree/build /Users/goroyabu/Soft/gradedHittree/build/ruby /Users/goroyabu/Soft/gradedHittree/build/ruby/CMakeFiles/eventTree2HitTreeGen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ruby/CMakeFiles/eventTree2HitTreeGen.dir/depend

