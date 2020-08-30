cmake_minimum_required(VERSION 3.17)
project(CNN)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})
set(CNN_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src)
set(MNIST_SOURCE_DIR ${PROJECT_SOURCE_DIR}/src/examples/mnist)
set(DATA_DIR ${PROJECT_SOURCE_DIR}/data/)

add_executable(CNN
               main.cpp
               src/cnn/utils/utils.h
               src/cnn/utils/utils.cpp
               src/cnn/utils/shape.h
               src/cnn/utils/log.h
               src/cnn/utils/array3d.h
               src/cnn/utils/array3d_math.h)


if(CMAKE_CXX_COMPILER_ID MATCHES GNU)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

enable_testing()

add_subdirectory(src/cnn)