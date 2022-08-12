//
// Created by p on 8/11/22.
//
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "../lib/manC.h"
#include <string.h>

void test_get_len(void **state) {


}

void test_init(void **state) {


}

void test_find(void **state) {

}

void test_insert(void **state) {

}

void test_removal(void **state) {

}

void test_print(void **state) {

}

static int group_setup(void **state) {
    struct head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str,&my_head);
    assert_return_code(1, TAILQ_EMPTY(&my_head));
    *state = &my_head;
    return 0;
}

static int group_teardown(void **state) {

    return 0;
}

int main(void) {
    // CMUnitTest 结构体是测试用例集（可以包含多个测试用例），每个测试用例可以设定可选的 startup 和 teardown 函数，用于负责执行测试前的初始化和测试后的销毁工作
    const struct CMUnitTest tests[] = {
            //  用了 cmocka_unit_test 宏来填充 CMUnitTest 结构体中的测试用例（ startup 和 teardown 为 NULL）
//            cmocka_unit_test(test_get_len),
//            cmocka_unit_test(test_find),
            cmocka_unit_test(test_init)
//            cmocka_unit_test(test_insert),
//            cmocka_unit_test(test_removal),
//            cmocka_unit_test(test_print)


    };
// cmocka_run_group_tests 函数用于启动测试并展示测试结果，可以为测试集指定全局的 startup 和 teardown（示例中都是NULL）。
    return cmocka_run_group_tests(tests, group_setup, group_teardown);

}