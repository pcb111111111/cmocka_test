//
// Created by p on 8/11/22.
//

#ifndef CTEST_QUEUE_H
#define CTEST_QUEUE_H

#endif //CTEST_QUEUE_H

#include <sys/queue.h>
#include <string.h>
#define ARRAY_MAX_SIZE 1000000
struct node {
    char c;
    int index;
    TAILQ_ENTRY(node) next;
};
TAILQ_HEAD(str_head, node);

int get_len(struct str_head *my_head);

void init(const char *str, struct str_head *my_head);

char *dump(struct str_head *my_head);

int find(struct str_head *my_head, char target);

int insert(struct str_head *my_head, char *target, int pos);

int removal(struct str_head *my_head, int begin, int len);
