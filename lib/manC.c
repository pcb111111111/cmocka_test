//
// Created by p on 8/11/22.
//

#include <stdlib.h>
#include "manC.h"
#include <stdio.h>


void init(const char *str, struct head *my_head) {
    int i = 0;
    //if(strlen(str)<0 || )
    while (*str) {
        struct node *e = (struct node *) malloc(sizeof(struct node));
        e->c = *str;
        e->index = i++;
        TAILQ_INSERT_TAIL(my_head, e, next);
        str++;
    }
}

void print(struct head *my_head) {
    struct node *n;
    TAILQ_FOREACH(n, my_head, next) {
        printf("%p %c %d\r\n", n, n->c, n->index);
    }
}

int get_len(struct head *my_head) {
    struct node *n;
    n = TAILQ_LAST(my_head, head);
    return n->index + 1;
}

int find(struct head *my_head, char target) {
    printf("input your target\n");
    int index = -1;
    getchar();
    scanf("%c", &target);
    struct node *n;
    TAILQ_FOREACH(n, my_head, next) {
        if (n->c == target) {
            index = n->index;
            printf("target %c first appear on index %d\n", target, index);
            return n->index;
        }
    }
    return -1;

}

void insert(struct head *my_head, char *target, int pos) {


    if (pos < 0 || pos >= get_len(my_head)) {
        puts("wrong pos");
        return;
    }
    struct node *n;
    int tag = 0;
    TAILQ_FOREACH(n, my_head, next) {
        if (n->index == pos) {
            for (; tag < strlen(target); tag++) {
                struct node *e = (struct node *) malloc(sizeof(struct node));
                e->c = target[tag];
                e->index = n->index + tag;
                TAILQ_INSERT_BEFORE(n, e, next);
            }
        }
        if (tag != 0) {
            n->index += tag;
        }
    }
    print(my_head);
}

void removal(struct head *my_head,int begin, int len) {

    scanf("%d %d", &begin, &len);
    if (begin < 0 || len + begin >= get_len(my_head)) {
        puts("wrong index");
        return;
    }
    struct node *n;
    TAILQ_FOREACH(n, my_head, next) {
        if (n->index == begin) {
            for (int i = 0; i < len; i++) {
                TAILQ_REMOVE(my_head, n, next);
            }
        }
    }
    print(my_head);


}


