# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zhangyuheng/workspace/appGo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zhangyuheng/workspace/appGo/build

# Utility rule file for appGo_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/appGo_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appGo_autogen.dir/progress.make

CMakeFiles/appGo_autogen: appGo_autogen/timestamp

appGo_autogen/timestamp: /opt/homebrew/opt/qt@6/share/qt/libexec/moc
appGo_autogen/timestamp: /opt/homebrew/opt/qt@6/share/qt/libexec/uic
appGo_autogen/timestamp: CMakeFiles/appGo_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target appGo"
	/opt/homebrew/bin/cmake -E cmake_autogen /Users/zhangyuheng/workspace/appGo/build/CMakeFiles/appGo_autogen.dir/AutogenInfo.json ""
	/opt/homebrew/bin/cmake -E touch /Users/zhangyuheng/workspace/appGo/build/appGo_autogen/timestamp

CMakeFiles/appGo_autogen.dir/codegen:
.PHONY : CMakeFiles/appGo_autogen.dir/codegen

appGo_autogen: CMakeFiles/appGo_autogen
appGo_autogen: appGo_autogen/timestamp
appGo_autogen: CMakeFiles/appGo_autogen.dir/build.make
.PHONY : appGo_autogen

# Rule to build all files generated by this target.
CMakeFiles/appGo_autogen.dir/build: appGo_autogen
.PHONY : CMakeFiles/appGo_autogen.dir/build

CMakeFiles/appGo_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appGo_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appGo_autogen.dir/clean

CMakeFiles/appGo_autogen.dir/depend:
	cd /Users/zhangyuheng/workspace/appGo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangyuheng/workspace/appGo /Users/zhangyuheng/workspace/appGo /Users/zhangyuheng/workspace/appGo/build /Users/zhangyuheng/workspace/appGo/build /Users/zhangyuheng/workspace/appGo/build/CMakeFiles/appGo_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/appGo_autogen.dir/depend

