#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG

//
// Function declarations
//
bool isPalindrome(int x);

//
// Function definitions
//

////////////////////////////////////////////////////////////////
// @name isPalindrome
// @description Determines if input is a palindrome
// @input int x - integer
// @output bool isPalindrom - True if x is a palindrome
////////////////////////////////////////////////////////////////
bool isPalindrome(int x) {
   int nums[100];
   int res, i = 0, j = 0, isOdd, num1, num2;

   if (x < 0) {
      return false;
   } else {
      res = x;
   }

   while (res) {
      // get lsb
      nums[i] = res % 10;
      // shift right
      res = res / 10;

   #ifdef DEBUG
      printf("nums[%d] = %d; res = %d\n", i, nums[i], res);
   #endif
         i += 1;
   }
   // number of elements in first and second half of num
   j = i / 2;

   for (int k = 0; k < j; k++) {
      if (nums[k] != nums[i-1-k]) {
         return false;
      }
   }

#ifdef DEBUG
   printf("j: %d\n", j);
#endif
   return true;
}

int main() {
   int x = -121;
   bool y;

   y = isPalindrome(x);

#ifdef DEBUG
   printf("Is 'x' a palindrome: %d\n", y);
#endif // DEBUG

   return 0;
}