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

# Include any dependencies generated for this target.
include CMakeFiles/appGo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/appGo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/appGo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/appGo.dir/flags.make

appGo_autogen/timestamp: /opt/homebrew/opt/qt@6/share/qt/libexec/moc
appGo_autogen/timestamp: /opt/homebrew/opt/qt@6/share/qt/libexec/uic
appGo_autogen/timestamp: CMakeFiles/appGo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target appGo"
	/opt/homebrew/bin/cmake -E cmake_autogen /Users/zhangyuheng/workspace/appGo/build/CMakeFiles/appGo_autogen.dir/AutogenInfo.json ""
	/opt/homebrew/bin/cmake -E touch /Users/zhangyuheng/workspace/appGo/build/appGo_autogen/timestamp

CMakeFiles/appGo.dir/codegen:
.PHONY : CMakeFiles/appGo.dir/codegen

CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o: CMakeFiles/appGo.dir/flags.make
CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o: appGo_autogen/mocs_compilation.cpp
CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o: CMakeFiles/appGo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o -MF CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o -c /Users/zhangyuheng/workspace/appGo/build/appGo_autogen/mocs_compilation.cpp

CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangyuheng/workspace/appGo/build/appGo_autogen/mocs_compilation.cpp > CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.i

CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangyuheng/workspace/appGo/build/appGo_autogen/mocs_compilation.cpp -o CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.s

CMakeFiles/appGo.dir/src/main.cpp.o: CMakeFiles/appGo.dir/flags.make
CMakeFiles/appGo.dir/src/main.cpp.o: /Users/zhangyuheng/workspace/appGo/src/main.cpp
CMakeFiles/appGo.dir/src/main.cpp.o: CMakeFiles/appGo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/appGo.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/appGo.dir/src/main.cpp.o -MF CMakeFiles/appGo.dir/src/main.cpp.o.d -o CMakeFiles/appGo.dir/src/main.cpp.o -c /Users/zhangyuheng/workspace/appGo/src/main.cpp

CMakeFiles/appGo.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/appGo.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangyuheng/workspace/appGo/src/main.cpp > CMakeFiles/appGo.dir/src/main.cpp.i

CMakeFiles/appGo.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/appGo.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangyuheng/workspace/appGo/src/main.cpp -o CMakeFiles/appGo.dir/src/main.cpp.s

CMakeFiles/appGo.dir/src/mainwindow.cpp.o: CMakeFiles/appGo.dir/flags.make
CMakeFiles/appGo.dir/src/mainwindow.cpp.o: /Users/zhangyuheng/workspace/appGo/src/mainwindow.cpp
CMakeFiles/appGo.dir/src/mainwindow.cpp.o: CMakeFiles/appGo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/appGo.dir/src/mainwindow.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/appGo.dir/src/mainwindow.cpp.o -MF CMakeFiles/appGo.dir/src/mainwindow.cpp.o.d -o CMakeFiles/appGo.dir/src/mainwindow.cpp.o -c /Users/zhangyuheng/workspace/appGo/src/mainwindow.cpp

CMakeFiles/appGo.dir/src/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/appGo.dir/src/mainwindow.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangyuheng/workspace/appGo/src/mainwindow.cpp > CMakeFiles/appGo.dir/src/mainwindow.cpp.i

CMakeFiles/appGo.dir/src/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/appGo.dir/src/mainwindow.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangyuheng/workspace/appGo/src/mainwindow.cpp -o CMakeFiles/appGo.dir/src/mainwindow.cpp.s

CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o: CMakeFiles/appGo.dir/flags.make
CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o: /Users/zhangyuheng/workspace/appGo/src/widgets/appcard.cpp
CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o: CMakeFiles/appGo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o -MF CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o.d -o CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o -c /Users/zhangyuheng/workspace/appGo/src/widgets/appcard.cpp

CMakeFiles/appGo.dir/src/widgets/appcard.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/appGo.dir/src/widgets/appcard.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangyuheng/workspace/appGo/src/widgets/appcard.cpp > CMakeFiles/appGo.dir/src/widgets/appcard.cpp.i

CMakeFiles/appGo.dir/src/widgets/appcard.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/appGo.dir/src/widgets/appcard.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangyuheng/workspace/appGo/src/widgets/appcard.cpp -o CMakeFiles/appGo.dir/src/widgets/appcard.cpp.s

CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o: CMakeFiles/appGo.dir/flags.make
CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o: /Users/zhangyuheng/workspace/appGo/src/widgets/appgridview.cpp
CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o: CMakeFiles/appGo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o -MF CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o.d -o CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o -c /Users/zhangyuheng/workspace/appGo/src/widgets/appgridview.cpp

CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zhangyuheng/workspace/appGo/src/widgets/appgridview.cpp > CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.i

CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zhangyuheng/workspace/appGo/src/widgets/appgridview.cpp -o CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.s

# Object files for target appGo
appGo_OBJECTS = \
"CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/appGo.dir/src/main.cpp.o" \
"CMakeFiles/appGo.dir/src/mainwindow.cpp.o" \
"CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o" \
"CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o"

# External object files for target appGo
appGo_EXTERNAL_OBJECTS =

appGo: CMakeFiles/appGo.dir/appGo_autogen/mocs_compilation.cpp.o
appGo: CMakeFiles/appGo.dir/src/main.cpp.o
appGo: CMakeFiles/appGo.dir/src/mainwindow.cpp.o
appGo: CMakeFiles/appGo.dir/src/widgets/appcard.cpp.o
appGo: CMakeFiles/appGo.dir/src/widgets/appgridview.cpp.o
appGo: CMakeFiles/appGo.dir/build.make
appGo: /opt/homebrew/opt/qt@6/lib/QtWidgets.framework/Versions/A/QtWidgets
appGo: /opt/homebrew/opt/qt@6/lib/QtNetwork.framework/Versions/A/QtNetwork
appGo: /opt/homebrew/opt/qt@6/lib/QtSql.framework/Versions/A/QtSql
appGo: /opt/homebrew/opt/qt@6/lib/QtGui.framework/Versions/A/QtGui
appGo: /opt/homebrew/opt/qt@6/lib/QtCore.framework/Versions/A/QtCore
appGo: CMakeFiles/appGo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/zhangyuheng/workspace/appGo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable appGo"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/appGo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/appGo.dir/build: appGo
.PHONY : CMakeFiles/appGo.dir/build

CMakeFiles/appGo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/appGo.dir/cmake_clean.cmake
.PHONY : CMakeFiles/appGo.dir/clean

CMakeFiles/appGo.dir/depend: appGo_autogen/timestamp
	cd /Users/zhangyuheng/workspace/appGo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zhangyuheng/workspace/appGo /Users/zhangyuheng/workspace/appGo /Users/zhangyuheng/workspace/appGo/build /Users/zhangyuheng/workspace/appGo/build /Users/zhangyuheng/workspace/appGo/build/CMakeFiles/appGo.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/appGo.dir/depend

