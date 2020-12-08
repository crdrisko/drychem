### Lower Level CMake Script for DryChem ###
cmake_minimum_required(VERSION 3.12.0)
project(CppUtils VERSION 1.0.0)


### Options ###
if (units_build_all)
    set(units_build_tests ON PARENT_SCOPE)
    set(units_build_samples ON)
endif()


### Libraries / Executables ###
list(APPEND LIBRARIES cpp-units/include/cpp-units)
set(LIBRARIES ${LIBRARIES} PARENT_SCOPE)

if (units_build_samples)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DryChem_BINARY_DIR}/bin/samples)

    # add_executable(***Example cpp-units/libs/***/samples/***Example.cpp)

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${DryChem_BINARY_DIR}/bin)
endif()
