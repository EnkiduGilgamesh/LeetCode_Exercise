/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: Q14_Longest_Prefix                                                                      *
* Created Date: Monday Sep 26th 2022, 6:17:20 pm                                                   *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 27/09/2022 05:03:54                                                               *
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

#define MAX 15

char * longestCommonPrefix(char ** strs, int strsSize){
    char * common = (char *)malloc(sizeof(char) * MAX);

    int i = 0, j = 0, flag = 0;
    char fix = 'a';
    while(1){
        if(strs[0][j] == '\0') break;
        fix = strs[0][j];
        for(i = 1; i < strsSize; i++){
            if(strs[i][j] == fix) continue;
            else{
                flag = 1;
                break;
            }
        }
        if(flag != 1) common[j] = fix;
        else break;
        j++;
    }
    common[j] = '\0';
    return common;
}

int main(){
    //char strs[MAX][MAX];                                       //above is a variable, underneath is a pointer to a const

    int strsSize;
    scanf("%d", &strsSize);

    char ** strs=(char **)malloc(strsSize * sizeof(char*));     //use malloc to create space
	for (int i = 0; i < strsSize; i++)
	{
		strs[i] = (char*)malloc(MAX * sizeof(char));
	}

    for(int i = 0; i < strsSize; i++){                  //strs initalize successfully.
        scanf("%s", strs[i]);
    }

    printf("%s", longestCommonPrefix(strs, strsSize));

    return 0;
}
