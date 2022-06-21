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
   int mirNum = 0, num;

   if (x < 0) {
      return false;
   } else if (x == 0) {
      return true;
   } else {
      num = x;
   }

   while (mirNum < num) {
      // shift left
      mirNum *= 10;
      // add lsb
      mirNum += num % 10;

   #ifdef DEBUG
      printf("num: %d, mirNum: %d\n", num, mirNum);
   #endif

      // shift right
      num /= 10;
   }

   if ((mirNum == num) || (mirNum/10 == num)) {
      return true;
   } else {
      return false;
   }

   return false;
}

int main() {
   int x = 1221;
   bool y;

   y = isPalindrome(x);

#ifdef DEBUG
   printf("Is 'x' a palindrome: %d\n", y);
#endif // DEBUG

   return 0;
}