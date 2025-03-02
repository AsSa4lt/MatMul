cmake_minimum_required(VERSION 3.10)
project(MatMul)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)




# Create executable
add_executable(matmul src/main.cpp)

# Link XNNPACK
target_link_libraries(matmul)
