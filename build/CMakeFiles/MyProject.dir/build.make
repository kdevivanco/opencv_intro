# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.26.4/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.26.4/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build

# Include any dependencies generated for this target.
include CMakeFiles/MyProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyProject.dir/flags.make

CMakeFiles/MyProject.dir/main.cpp.o: CMakeFiles/MyProject.dir/flags.make
CMakeFiles/MyProject.dir/main.cpp.o: /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/main.cpp
CMakeFiles/MyProject.dir/main.cpp.o: CMakeFiles/MyProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/MyProject.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/MyProject.dir/main.cpp.o -MF CMakeFiles/MyProject.dir/main.cpp.o.d -o CMakeFiles/MyProject.dir/main.cpp.o -c /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/main.cpp

CMakeFiles/MyProject.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MyProject.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/main.cpp > CMakeFiles/MyProject.dir/main.cpp.i

CMakeFiles/MyProject.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MyProject.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/main.cpp -o CMakeFiles/MyProject.dir/main.cpp.s

# Object files for target MyProject
MyProject_OBJECTS = \
"CMakeFiles/MyProject.dir/main.cpp.o"

# External object files for target MyProject
MyProject_EXTERNAL_OBJECTS =

MyProject: CMakeFiles/MyProject.dir/main.cpp.o
MyProject: CMakeFiles/MyProject.dir/build.make
MyProject: /usr/local/lib/libopencv_gapi.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_stitching.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_alphamat.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_aruco.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_barcode.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_bgsegm.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_bioinspired.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_ccalib.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_dnn_objdetect.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_dnn_superres.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_dpm.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_face.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_freetype.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_fuzzy.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_hfs.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_img_hash.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_intensity_transform.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_line_descriptor.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_mcc.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_quality.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_rapid.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_reg.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_rgbd.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_saliency.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_sfm.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_stereo.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_structured_light.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_superres.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_surface_matching.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_tracking.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_videostab.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_viz.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_wechat_qrcode.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_xfeatures2d.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_xobjdetect.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_xphoto.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_shape.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_highgui.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_datasets.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_plot.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_text.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_ml.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_phase_unwrapping.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_optflow.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_ximgproc.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_video.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_videoio.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_imgcodecs.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_objdetect.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_calib3d.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_dnn.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_features2d.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_flann.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_photo.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_imgproc.4.7.0.dylib
MyProject: /usr/local/lib/libopencv_core.4.7.0.dylib
MyProject: CMakeFiles/MyProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MyProject"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyProject.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyProject.dir/build: MyProject
.PHONY : CMakeFiles/MyProject.dir/build

CMakeFiles/MyProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyProject.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyProject.dir/clean

CMakeFiles/MyProject.dir/depend:
	cd /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build /Users/macbookpro/Desktop/UTEC/OpenCV/opencv3test/build/CMakeFiles/MyProject.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyProject.dir/depend

