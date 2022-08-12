set(CMAKE_EXPORT_COMPILE_COMMANDS yes)

list(APPEND tests_names "test_demo")
list(APPEND tests_flags " ")


# Declare all tests targets
list(LENGTH tests_names count)
math(EXPR count "${count} - 1")
foreach (i RANGE ${count})
    list(GET tests_names ${i} test_name)
    list(GET tests_flags ${i} test_flags)

    if (test_name STREQUAL "test_demo")
        add_executable(${test_name} ${test_name}.c)
        target_link_libraries(${test_name} cmocka libs)
    endif ()
    add_test(${test_name} ${test_name})
endforeach ()
