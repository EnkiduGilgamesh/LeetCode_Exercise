/*-*- gcc 10.3.0 -*-*/
/*-*- coding:utf-8 -*-*/
/***************************************************************************************************
* File: \main2.c                                                                                   *
* Project: Q870_Advantage_Shuffle                                                                  *
* Created Date: Saturday Oct 8th 2022, 11:54:38 am                                                 *
* Author: Wenren Muyan                                                                             *
* Comments:                                                                                        *
* --------------------------------------------------------------------------------                 *
* Last Modified: 8/10/2022 07:04:5                                                                 *
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

void mergeSortRecursive(int * l, int * reg, int start, int end){
    if(start >= end) return;

    int len = end - start;
    int mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;

    mergeSortRecursive(l, reg, start1, end1);
    mergeSortRecursive(l, reg, start2, end2);

    int k = start;
    while(start1 <= end1 && start2 <= end2){
        reg[k++] = l[start1] < l[start2] ? l[start1++] : l[start2++];
    }
    while(start1 <= end1){
        reg[k++] = l[start1++];
    }
    while(start2 <= end2){
        reg[k++] = l[start2++];
    }

    for(int i = start; i <= end; i++){
        l[i] = reg[i];
    }
}

void mergeSort(int * l, int len){
    int reg[len];
    mergeSortRecursive(l, reg, 0, len - 1);
}

// Use merge sort first. O(nlogn)
int* advantageCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    int * res = (int *)malloc(sizeof(int *) * (nums1Size));

    mergeSort(nums1, nums1Size);

    int k = 0, smallPos = 0, flag = 0;

    for(int i = 0; i < nums2Size; i++){
        flag = 0;
        for(int j = smallPos; j < nums1Size; j++){
            if(nums1[j] > nums2[i]){
                flag = 1;
                res[i] = nums1[j];
                nums1[j] = -1;
                break;
            }
        }

        if(!flag) res[i] = nums1[smallPos++];

        while(nums1[smallPos] == -1 && smallPos < ) smallPos++;
    }

    *returnSize = nums1Size;
    return res;
}

int main(){
    int nums1[4] = {2,7,11,15};
    int nums2[4] = {1,10,4,11};
    int * returnSize;
    *returnSize = 4;
    int * res = advantageCount(nums1, 4, nums2, 4, returnSize);

    for(int i = 0; i < *returnSize; i++){
        printf("%d ", res[i]);
    }

    return 0;
}
