//
// Created by p on 8/11/22.
//
#include <stdio.h>
#include "lib/manC.h"
#include <string.h>
#define ARRAY_MAX_SIZE 1000000

int main() {
    struct head my_head;
    TAILQ_INIT(&my_head);
    int flag = 0, out = 0;
    char str[ARRAY_MAX_SIZE];
    printf("%d", TAILQ_EMPTY(&my_head));
    puts("input your string:");
    scanf("%s",str);
    init(str, &my_head);
    while (1) {
        printf("Input your command:\n");
        scanf("%d", &flag);
        switch (flag) {
            case 1:{
                char target;
                printf("Input your target character");
                scanf("%c",&target);
                find(&my_head,target);
                break;
            }

            case 2:{
                int pos;char *arr;
                printf("Input your begin index and string you want to insert\n");
                scanf("%s %d",arr,&pos);
                insert(&my_head,arr,pos);
                break;
            }

            case 3:{
                int begin,len;
                printf("Input your begin index and length you want to remove\n");
                scanf("%d %d",&begin,&len);
                removal(&my_head,begin,len);
                break;
            }

            case 4:{
                print(&my_head);
                break;
            }

            case 0:{
                out = 1;
                break;
            }

            default:{
                break;
            }

        }
        if (out == 1) {
            break;
        }
    }

}




