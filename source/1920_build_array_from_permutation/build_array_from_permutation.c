#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* buildArray(int* nums, int numsSize, int* returnSize){
   int* pRetArr;

   *returnSize = numsSize;
   pRetArr = (int *) malloc(sizeof(int) * numsSize);

   for (int i = 0; i < numsSize; i++){
      pRetArr[i] = nums[nums[i]];
   }

   return pRetArr;
}

int main() {
   int numsSize = 5;
   int nums[] = {0,2,1,5,3,4};
   int returnSize;
   int* pRetArr;

   pRetArr = buildArray(nums, numsSize, &returnSize);

#ifdef DEBUG
   for (int i = 0; i < numsSize; i++) {
      printf("Idx: %d\tVal: %d\n", i, pRetArr[i]);
   }
#endif

   return 0;
}