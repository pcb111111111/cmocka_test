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

void test_demo_init(void **state)
{
}


static int group_setup(void **state)
{
	teststate_t *teststate = calloc(1, sizeof(teststate_t));
	*state = teststate;

	return 0;
}

/**
 * This is run once after all group tests
 */
static int group_teardown(void **state)
{
	teststate_t *teststate = *state;
	free(teststate);

	return 0;
}

int main(void)
{
	const struct CMUnitTest demo_tests[] = {
		cmocka_unit_test(test_demo_init),
	};

	return cmocka_run_group_tests(demo_tests, group_setup, group_teardown);
}
