# raytracing
## Planned features
- Different shading models (Phong, etc.)

## Setup
```bash
# Install vcpkg
git clone https://github.com/Microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh

# Build project
cd ..
mkdir build && cd build
cmake .. -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
cmake --build .
```

## References
- [Ray Tracing In One Weekend](https://raytracing.github.io)
- Fundamentals of Computer Graphics (4th Edition)
- Real Time Rendering (4th Edition)
- Physically Based Rendering (4th Edition)
