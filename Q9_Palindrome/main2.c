/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main2.c                                                                                   *
* Project: Q9_Palindrome                                                                           *
* Created Date: Sunday Sep 25th 2022, 10:13:16 pm                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/09/2022 10:15:50                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool isPalindrome(int x){
    if(x < 0) return false;
    long long sum = 0, temp;
    temp = x;
    while(x > 0){
        int a = x % 10;
        sum = sum * 10 + a;
        x /= 10;
    }
    if(sum == temp) return true;
    else return false;
}

int main(){
    int x;
    scanf("%d", &x);
    bool check = isPalindrome(x);
    printf("%d", check);
    return 0;
}
