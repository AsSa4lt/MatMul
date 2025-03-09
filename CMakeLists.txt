cmake_minimum_required(VERSION 3.10)
project(MatMul)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${CMAKE_SOURCE_DIR}/include)

find_package(Eigen3 3.3 REQUIRED NO_MODULE)
include_directories(${EIGEN3_INCLUDE_DIR})

# Create executable
add_executable(matmul src/main.cpp src/NaiveMatMulBenchmark.cpp 
                        src/NaiveTiledMatMulBenchmark.cpp 
                        src/SIMDNaiveMatMulBenchmark.cpp
                        src/EigenMatMulBenchmark.cpp)

# Link XNNPACK
target_link_libraries(matmul)
