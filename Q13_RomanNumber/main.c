/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: Q13_RomanNumber                                                                         *
* Created Date: Sunday Sep 25th 2022, 7:36:39 pm                                                   *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 26/09/2022 06:36:15                                                               *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//#include<string.h>

#define MAX 15

int romanToInt(char * s){
    char * temp = s;
    int sSize = 0;
    int* numBit;

    while(*temp){
        sSize++;
        temp++;
    }

    numBit = (int *)malloc(sizeof(int)*sSize);

    temp = s;
    while(*temp){
        switch(*temp){
            case 'I': numBit[temp - s] = 1;break;
            case 'V': numBit[temp - s] = 5;break;
            case 'X': numBit[temp - s] = 10;break;
            case 'L': numBit[temp - s] = 50;break;
            case 'C': numBit[temp - s] = 100;break;
            case 'D': numBit[temp - s] = 500;break;
            case 'M': numBit[temp - s] = 1000;break;
            default: numBit[temp - s] = 0;break;
        }
        temp++;
    }

    //int cur = 0, next = numBit[0], sum = 0;
    int cur, next, sum = 0;
    for(int i = 0; i < sSize; i++){
        cur = numBit[i];
        if(i+1 < sSize) next = numBit[i+1];
        else next = 0;
        
        if(cur < next) sum -= cur;
        else sum += cur;
    }

    return sum;
}

int main(){
    char Rnum[MAX];                                  // Giving a storage when initialization is essential!!!
    printf("Please enter a roman number: ");
    scanf("%s", Rnum);
    //printf("%s", Rnum);
    printf("%d",romanToInt(Rnum));
    return 0;
}
