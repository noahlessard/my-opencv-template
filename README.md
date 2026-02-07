## Custom C++ OpenCV Template

This is a base template repo set up for me to use. It uses statically linked libs that I built from sources without DNN and video support, but that's ok for most of my applications. 
It also has an example #include compile definition for cmake.

### Setting up static libs

Go to the releases page, and download the release for your operating system.
Create a /libs folder in the root of this repo.
Extract the .zip file to the libs folder.

### Adding new static libs
Git clone the openCV library, run the cmake build:

```
cmake -DBUILD_SHARED_LIBS=OFF \
  -DBUILD_opencv_world=ON \
  -DBUILD_opencv_dnn=OFF \
  -DBUILD_opencv_videoio=OFF \
  -DWITH_FFMPEG=OFF \
  -DBUILD_TESTS=OFF \
  -DBUILD_PERF_TESTS=OFF \
  -DBUILD_EXAMPLES=OFF \
  -S . -B build

cmake --build build --config Debug
cmake --build build --config Release
```

The exact command will probably depend on your arch/os, but this is what I used.

Then, package /lib, /3rdparty, /include, and OpenCVConfig.cmake and OpenCVModules.cmake.
These go in your /libs folder