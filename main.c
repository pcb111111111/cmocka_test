//
// Created by p on 8/11/22.
//
#include <stdio.h>
#include "lib/man_c.h"
#include <string.h>


int main() {
    struct str_head my_head;
    TAILQ_INIT(&my_head);
    int flag = 0, out = 0;
    char str[ARRAY_MAX_SIZE];
    puts("input your string:");
    scanf("%s",str);
    init(str, &my_head);
    while (1) {
        printf("Input your command:\n");
        scanf("%d", &flag);
        switch (flag) {
            case 1:{
                char target;
                printf("Input your target character:\n");
                scanf("%c",&target);
                find(&my_head,target);
                break;
            }

            case 2:{
                int pos;char arr[ARRAY_MAX_SIZE] ;
                printf("Input your begin index and string you want to insert\n");
                scanf("%d %s",&pos,arr);
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
                puts(dump(&my_head));
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




