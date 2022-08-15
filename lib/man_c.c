//
// Created by p on 8/11/22.
//

#include <stdlib.h>
#include "man_c.h"
#include <stdio.h>


void init(const char *str, struct str_head *my_head) {
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


char *dump(struct str_head *my_head) {
    struct node *n;
    char *p= (char *)malloc(ARRAY_MAX_SIZE);
    int i = 0;
    TAILQ_FOREACH(n, my_head, next) {
        p[i++] = n->c;
    }
    return p;
}

int get_len(struct str_head *my_head) {
    struct node *n;
    n = TAILQ_LAST(my_head, str_head);
    return n->index + 1;
}

int find(struct str_head *my_head, char target) {
    int index = -1;
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

int insert(struct str_head *my_head, char *target, int pos) {

    if (pos < 0 || pos > get_len(my_head)) {
        puts("wrong pos");
        return -1;
    }
    struct node *n;
    int tag = 0;

    if (pos == get_len(my_head)) {
        for (; tag < strlen(target); tag++) {
            n = TAILQ_LAST(my_head, str_head);
            struct node *e = (struct node *) malloc(sizeof(struct node));
            e->c = target[tag];
            e->index = n->index + 1;
            TAILQ_INSERT_AFTER(my_head, n, e, next);
        }
        n = NULL;
        tag = 0;
    } else {
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
    }
    return 1;
}

int removal(struct str_head *my_head, int begin, int len) {

    if (begin < 0 || len + begin > get_len(my_head) || begin >= get_len(my_head)) {
        puts("wrong index");
        return -1;
    }
    struct node *n;
    //put len1 as a tmp variable
    int tag = 0, len1 = len;
    TAILQ_FOREACH(n, my_head, next) {
        if (n->index == begin && len1 > 0) {
            TAILQ_REMOVE(my_head, n, next);
            len1--;
            tag = 1;
            begin++;
        }
        if (tag == 1 && n != NULL)
            n->index -= len;

    }
    if (my_head != NULL)
        puts(dump(my_head));
    return 1;
}


