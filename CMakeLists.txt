cmake_minimum_required(VERSION 3.10)
project(cmocka C)
set(CMAKE_C_STANDARD 99)

add_executable(cmocka main.c lib/manC.c lib/manC.h )
add_executable(test_man_collection test/test_man_collection.c lib/manC.c lib/manC.h /usr/local/include/cmocka.h)