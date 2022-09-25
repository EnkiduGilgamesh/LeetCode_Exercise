/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: Q9_Palindrome                                                                           *
* Created Date: Thursday Sep 22nd 2022, 8:33:41 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 25/09/2022 09:18:10                                                               *
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
    if(x == 0) return true;
    int digit = 0;
    int temX = x;
    do{
        digit++;
        temX /= 10;
    }while(temX > 0);
    int* numX = (int *)malloc(sizeof(int)*digit);

    temX = x;
    int ten = 10;
    for(int i = digit-1; i >= 0; i--){
        numX[i] = (temX % ten) / (ten / 10);
        temX /= 10;
    }
    for(int j = 0; j < digit / 2; j++){
        if(numX[j] != numX[digit-1-j]) return false;
        else continue;
    }
    return true;
}

int main(){
    int x;
    scanf("%d", &x);
    bool check = isPalindrome(x);
    printf("%d", check);
    return 0;
}
