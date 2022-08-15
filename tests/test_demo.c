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
    struct str_head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    assert_int_equal(7, get_len(&my_head));

}

void test_find(void **state) {
    struct str_head my_head;
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

void test_dump(void **state) {
    struct str_head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    char *tmp = dump(&my_head);
    assert_string_equal(str, tmp);
    free(tmp);

}

void test_insert(void **state) {
    struct str_head my_head;
    TAILQ_INIT(&my_head);
    char *str = "b";
    init(str, &my_head);
    char *tmp = dump(&my_head);
    assert_string_equal(str, tmp);
    free(tmp);
    assert_int_equal(1, insert(&my_head, "de", 1));
    assert_int_equal(1, insert(&my_head, "0xa", 0));
    assert_int_equal(1, insert(&my_head, "c", 4));
    tmp = dump(&my_head);
    assert_string_equal("0xabcde", tmp);
    free(tmp);
    assert_int_equal(-1, insert(&my_head, " ", -1));
    assert_int_equal(-1, insert(&my_head, " ", get_len(&my_head) + 1));
}

void test_removal(void **state) {
    struct str_head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    char *tmp = dump(&my_head);
    assert_string_equal("abcdefg",tmp);
    free(tmp);
    assert_int_equal(removal(&my_head, 0, 2), 1);
    tmp = dump(&my_head);
    assert_string_equal("cdefg", dump(&my_head));
    free(tmp);
    //bad cases
    assert_int_equal(removal(&my_head, -1, 2), -1);
    assert_int_equal(removal(&my_head, 7, 2), -1);
    assert_int_equal(removal(&my_head, 0, 9), -1);
    //test removal all
    assert_int_equal(removal(&my_head, 0, 5), 1);
}


static int group_setup(void **state) {
    struct str_head my_head;
    TAILQ_INIT(&my_head);
    char *str = "abcdefg";
    init(str, &my_head);
    assert_string_equal("abcdefg", dump(&my_head));

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
            cmocka_unit_test(test_dump)


    };
// cmocka_run_group_tests 函数用于启动测试并展示测试结果，可以为测试集指定全局的 startup 和 teardown（示例中都是NULL）。
    return cmocka_run_group_tests(tests, group_setup, group_teardown);

}
