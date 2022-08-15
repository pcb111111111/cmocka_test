//
// Created by p on 8/11/22.
//

#ifndef CTEST_QUEUE_H
#define CTEST_QUEUE_H

#endif //CTEST_QUEUE_H

#include <sys/queue.h>
#include <string.h>

struct node {
    char c;
    int index;
    TAILQ_ENTRY(node)
            next;
};
TAILQ_HEAD(head, node
);

int get_len(struct head *my_head);
void init(const char *str, struct head *my_head);
void print(struct head *my_head);
int find(struct head *my_head,char target);
int insert(struct head *my_head,char *target,int pos);
int removal(struct head *my_head,int begin,int len);
