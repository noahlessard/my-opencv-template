# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)
# this is needed  for static linking!!
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


# define project name
project ("opencvTemplateMain")

# OpenCV keywork will tell us the config file for OpenCV starts with OpenCV
# so Cmake will look there (where? depends on OpenCV_DIR), and set include_dirs and _libs.
# Also need to tell OpenCV to use static .libs

set(OpenCV_DIR "D:/cpp/opencv-4.x/build")
set (OpenCV_STATIC ON)

# make it required (just so it errors if it can't find)
find_package (OpenCV REQUIRED) 

# tell it specifically to use the world version and not the broken up libs
set(OpenCV_LIBS 
    debug ${OpenCV_DIR}/lib/Debug/opencv_world4140d.lib
    optimized ${OpenCV_DIR}/lib/Release/opencv_world4140.lib
)

# Add OpenCV's header file directories to the include path
include_directories(${OpenCV_INCLUDE_DIRS})

# Move needed asset files into the out folder
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/${CMAKE_PROJECT_NAME})

# then, move onto this sub-dirs cmakelists, 
add_subdirectory ("opencvTemplateMain")

