/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main.c                                                                                    *
* Project: Q870_Advantage_Shuffle                                                                  *
* Created Date: Saturday Oct 8th 2022, 8:14:19 am                                                  *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 8/10/2022 04:47:44                                                                *
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

// greedy algorithm. return the smallest number which is bigger than nums2[i], otherwise the smallest in nums1
// this program is overflow the time limits in LeetCode.
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * res = (int *)malloc(sizeof(int *) * (nums2Size));

    for(int i = 0; i < nums2Size; i++){
        int cur = -1, pos1 = -1, pos2 = -1, small = -1;

        //record the samllest or the bigger.
        for(int j = 0; j < nums1Size; j++){
            if(nums1[j] > nums2[i] && (cur == -1 || nums1[j] < cur)){
                cur = nums1[j];
                pos1 = j;
            }
            if(nums1[j] < small || small == -1){
                small = nums1[j];
                pos2 = j;
            }
        }
        
        //Drop out the result, while assignment
        if(cur != -1){
            res[i] = cur;
            for(int k = pos1; k < nums1Size - 1; k++){
                nums1[k] = nums1[k+1];
            }
        }
        else{
            res[i] = small;
            for(int k = pos2; k < nums1Size - 1; k++){
                nums1[k] = nums1[k+1];
            }
        }

        nums1Size--;
    }

    return res;
}

int main(){
    int nums1[4] = {12,24,8,32};
    int nums2[4] = {13,25,32,11};
    int * returnSize;
    *returnSize = 4;
    int * res = advantageCount(nums1, 4, nums2, 4, returnSize);

    for(int i = 0; i < *returnSize; i++){
        printf("%d ", res[i]);
    }

    return 0;
}
