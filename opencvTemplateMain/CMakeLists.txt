# CMakeList.txt : CMake project for opencvExperiments, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (${PROJECT_NAME} "opencvTemplateMain.cpp" "opencvTemplateMain.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)
endif()

# tell cmake that this is a statically linked program now
target_compile_options(${PROJECT_NAME} PRIVATE 
    $<$<CONFIG:Release>:/MT>
    $<$<CONFIG:Debug>:/MTd>
)

# Link OpenCV world + all 3rdparty libs
target_link_libraries(${PROJECT_NAME} 
    # OpenCV
    debug ${OpenCV_DIR}/lib/Debug/opencv_world4140d.lib
    optimized ${OpenCV_DIR}/lib/Release/opencv_world4140.lib
    
    # Third-party libs (Release)
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/ade.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/IlmImf.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/ipphal.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/ippiw.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/ittnotify.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/libjpeg-turbo.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/libopenjp2.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/libpng.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/libprotobuf.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/libtiff.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/libwebp.lib
    optimized ${OpenCV_DIR}/3rdparty/lib/Release/zlib.lib
    optimized ${OpenCV_DIR}/3rdparty/ippicv/ippicv_win/icv/lib/intel64/ippicvmt.lib
    
    # Windows system libraries
    comctl32 gdi32 ole32 setupapi ws2_32 vfw32
)

# link the library to this executable
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})

# set console setting
# don't use option, it will get cached!
set(ENABLE_CONSOLE OFF)
if(ENABLE_CONSOLE)
    # tell main program about it
    target_compile_definitions(${PROJECT_NAME} PRIVATE ENABLE_CONSOLE)
else()
    # need this to use WinMain (which changes entry from console to windows gui)
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
endif()