#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

int* twoSum(int* pNums, int numsSize, int target, int* pReturnSize) {
    int i, j;

    *pReturnSize = 2;

    int *pNumsInd = (int*)malloc(*pReturnSize * sizeof(int));

    for (i = 0; i < numsSize; i++) {
        for (j = i + 1; j < numsSize; j++) {
            if ((pNums[i] + pNums[j]) == target) {
                pNumsInd[0] = i;
                pNumsInd[1] = j;
                return pNumsInd;
            }
        }
    }

    return NULL;
}

int main() {
   int target = 9;
   int numsSize = 4;
   int nums[] = {2,7,11,15};
   int* pNums = &nums[0];
   int returnSize = 0;
   int* pNumsInd = NULL;

   pNumsInd = twoSum(pNums, numsSize, target, &returnSize);

#ifdef DEBUG
   printf("Target: %d\n", target);
   printf("Nums Size: %d\n", numsSize);
   printf("Nums: [");
   for(int i = 0; i < numsSize; i++) {
      printf(" %d", nums[i]);
   }
   printf("]\n\n");
   printf("Nums Index: [");
   for(int i = 0; i < returnSize; i++) {
      printf(" %d", pNumsInd[i]);
   }
   printf("]\n");
#endif

   free(pNumsInd);

   return 0;
}