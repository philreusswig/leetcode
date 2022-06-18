#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG

//
// Function declarations
//
int findMin(int* nums, int numsSize);
int findMax(int* nums, int numsSize);
int findGCD(int* nums, int numsSize);

//
// Function definitions
//

////////////////////////////////////////////////////////////////
// @name findMin
// @description Find minimum element of input array
// @input int* nums - Array of numbers
// @input int numsSize - Number of elements in nums array
// @output int min - Minimum element of nums array
////////////////////////////////////////////////////////////////
int findMin(int* nums, int numsSize) {
   int min;

   min = nums[0];
   for (int i = 0; i < numsSize; i++) {
      if (nums[i] < min) {
         min = nums[i];
      }
   }

   return min;
}

////////////////////////////////////////////////////////////////
// @name findMax
// @description Find maximum element of input array
// @input int* nums - Array of numbers
// @input int numsSize - Number of elements in nums array
// @output int max - Maximum element of nums array
////////////////////////////////////////////////////////////////
int findMax(int* nums, int numsSize) {
   int max;

   max = nums[0];
   for (int i = 0; i < numsSize; i++) {
      if (nums[i] > max) {
         max = nums[i];
      }
   }

   return max;
}

////////////////////////////////////////////////////////////////
// @name findGCD
// @description Find greatest common divisor of the least and greatest elements of nums array
// @input int* nums - Array of numbers
// @input int numsSize - Number of elements in nums array
// @output int gcd - Greatest common divisor of the least and greatest elements of nums array
////////////////////////////////////////////////////////////////
int findGCD(int* nums, int numsSize) {
   int max, min, gcd = 0;

   min = findMin(nums, numsSize);
   max = findMax(nums, numsSize);

   for (int i = 1; i <= min; i++) {
      if ((max % i == 0) && (min % i == 0)) {
         gcd = i;
      }
   }
   return gcd;
}

int main() {
   int numsSize = 4;
   int nums[4] = {100, 200, 100, 50};
   int* pNums = &nums[0];
   int gcd;

#ifdef DEBUG
   printf("Input Numbers:");
   for (int i = 0; i < numsSize; i++) {
      printf(" %d ", nums[i]);
   }
   printf("\n");

   printf("Minimum of Numbers: %d\n", findMin(pNums, numsSize));
   printf("Maximum of Numbers: %d\n", findMax(pNums, numsSize));
#endif // DEBUG

   gcd = findGCD(pNums, numsSize);

#ifdef DEBUG
   printf("Greatest Common Divisor: %d\n", gcd);
#endif // DEBUG

   return 0;
}