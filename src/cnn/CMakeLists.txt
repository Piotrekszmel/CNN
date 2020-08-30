cmake_minimum_required(VERSION 3.9)

project(cnn CXX)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
        utils/shape.h
        utils/utils.h
        utils/utils.cpp
        utils/log.h
        utils/array3d.h
        utils/array3d_math.h)

add_library(cnn SHARED STATIC ${SOURCES})

target_include_directories(cnn PRIVATE ${CNN_SOURCE_DIR})

install(TARGETS cnn DESTINATION lib)