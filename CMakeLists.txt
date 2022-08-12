cmake_minimum_required(VERSION 3.10)
project(demo C)
set(CMAKE_C_STANDARD 99)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
option(CodeCoverage "CodeCoverage" ON)
set(CMAKE_BUILD_TYPE Debug)


set(CMAKE_CXX_FLAGS "-g -O0 -fprofile-arcs -ftest-coverage")
set(CMAKE_C_FLAGS "-g -O0 -Werror -Wall -fprofile-arcs -ftest-coverage -Wno-unused-function")

aux_source_directory(lib DIR_LIB)
add_library(libs ${DIR_LIB})


add_executable(demo main.c)

target_link_libraries(demo libs)

if (CodeCoverage MATCHES ON)
    include(CodeCoverage)
    SETUP_TARGET_FOR_COVERAGE(ctest_with_coverage ctest coverage)
    SETUP_TARGET_FOR_COVERAGE_COBERTURA(
            ctest_with_cobertura ctest coverage --gtest_output=xml:coverage.junit.xml)
endif ()

enable_testing()
add_subdirectory(tests)
