#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize){
   int* pRet;

   *returnSize = 2 * numsSize;
   pRet = (int *) malloc(sizeof(int) * *returnSize);

   for (int i = 0; i < 2; i++) {
      for (int j = 0; j < numsSize; j++) {
         pRet[j + i*numsSize] = nums[j];

      #ifdef DEBUG
         printf("Concat: %d ", pRet[j+i*numsSize]);
      #endif
      }
   }
#ifdef DEBUG
   printf("\n");
#endif

#ifdef DEBUG
   printf("NumsSize: %d\n", numsSize);
   printf("RetSize: %d\n", *returnSize);
#endif

   return pRet;

}

int main() {
   int numsSize = 4;
   int nums[] = {0,1,2,3};
   int returnSize = 0;

   getConcatenation(nums, numsSize, &returnSize);

   return 0;
}