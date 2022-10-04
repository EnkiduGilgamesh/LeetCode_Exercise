/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: Q3_Add_List                                                                             *
* Created Date: Thursday Sep 29th 2022, 8:29:35 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 29/09/2022 09:20:1                                                                *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
}l;

typedef struct ListNode list;

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    list * l3 = (list *)malloc(sizeof(list));
    l3->val = NULL;
    l3->next = NULL;

    list * cur1 = l1, * cur2 = l2, * cur3 = l3;
    int sum = 0, flag = 0;

    while(cur1 || cur2 || flag){
        int a1 = cur1 ? cur1->val : 0;
        int a2 = cur2 ? cur2->val : 0;

        sum = (a1 + a2 + flag) % 10;
        flag = (a1 + a2 + flag) / 10;

        cur3->val = sum;
        if(flag || (cur1&&cur1->next) || (cur2&&cur2->next)){
            list * n = (list *)malloc(sizeof(list));
            n->val = NULL;
            n->next = NULL;
            cur3->next = n;
            cur3 = cur3->next;
        }

        cur1 = cur1 ? cur1->next : NULL;
        cur2 = cur2 ? cur2->next : NULL;
    }

    return l3;
};
