/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: Q3_Longest_Unique_Strand                                                                *
* Created Date: Thursday Sep 29th 2022, 9:37:43 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 1/10/2022 09:43:8                                                                 *
* Modified By: Wenren Muyan                                                                        *
* --------------------------------------------------------------------------------                 *
* Copyright (c) 2022 - future Wenren Muyan                                                         *
* --------------------------------------------------------------------------------                 *
* HISTORY:                                                                                         *
* Date				By				Comments                                                       *
* --------------------------------------------------------------------------------                 *
***************************************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char * s){
    int len = strlen(s);

    int res = 0, j = 0;
    for(int i = 0; i < len; i++){
        int cur = j, flag = 0;
  
        while(cur < i){
            if(s[cur] == s[i]){
                j = cur + 1;
                flag = 1;
                break;
            }
            else{
                cur++;
            }
        }

        if(!flag && res < i - j + 1) res = i - j + 1;
    }

    return res;
}

int main(){
    char s[15];

    scanf("%s", s);

    printf("%d", lengthOfLongestSubstring(s));

    return 0;
}
