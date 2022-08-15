#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <sys/time.h>

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#include "cmocka.h"

typedef struct {
    int test;
} teststate_t;
//
// Created by p on 8/11/22.
//
#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <stdint.h>
#include <cmocka.h>
#include "../lib/man_c.h"
#include <string.h>

void test_get_len(void **state) {
    struct head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    assert_int_equal(7, get_len(&my_head));

}

void test_find(void **state) {
    struct head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    char target1 = 'b';
    char target2 = 'c';
    char target3 = 'z';
    assert_int_equal(find(&my_head, target1), 1);
    assert_int_equal(find(&my_head, target2), 2);
    assert_int_equal(find(&my_head, target3), -1);
}

void test_insert(void **state) {
    struct head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    char *target = "sss";
    int pos1 = 1, pos2 = -1, pos3 = 100;
    assert_int_equal(1, insert(&my_head, target, pos1));
    assert_int_equal(10, get_len(&my_head));
    assert_int_equal(1, find(&my_head, 's'));
    assert_int_equal(-1, insert(&my_head, target, pos2));
    assert_int_equal(-1, insert(&my_head, target, pos3));
}

void test_removal(void **state) {
    struct head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    int begin1 = 0, len1 = 2;
    //bad cases
    int begin2 = -1, len2 = 2;
    int begin3 = 7, len3 = 2;
    int begin4 = 0, len4 = 9;
    assert_int_equal(removal(&my_head, begin1, len1), 1);
    assert_int_equal(-1, find(&my_head, 'a'));
    assert_int_equal(-1, find(&my_head, 'b'));
    assert_int_equal(removal(&my_head, begin2, len2), -1);
    assert_int_equal(removal(&my_head, begin3, len3), -1);
    assert_int_equal(removal(&my_head, begin4, len4), -1);
    //test removal all
    assert_int_equal(removal(&my_head,0,5),1);
}


static int group_setup(void **state) {
    struct head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    assert_return_code(1, TAILQ_EMPTY(&my_head));
    return 0;
}

static int group_teardown(void **state) {

    return 0;
}

int main(void) {
    // CMUnitTest 结构体是测试用例集（可以包含多个测试用例），每个测试用例可以设定可选的 startup 和 teardown 函数，用于负责执行测试前的初始化和测试后的销毁工作
    const struct CMUnitTest tests[] = {
            //  用了 cmocka_unit_test 宏来填充 CMUnitTest 结构体中的测试用例（ startup 和 teardown 为 NULL）
            cmocka_unit_test(test_get_len),
            cmocka_unit_test(test_find),
            cmocka_unit_test(test_insert),
            cmocka_unit_test(test_removal),


    };
// cmocka_run_group_tests 函数用于启动测试并展示测试结果，可以为测试集指定全局的 startup 和 teardown（示例中都是NULL）。
    return cmocka_run_group_tests(tests, group_setup, group_teardown);

}
