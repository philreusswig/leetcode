#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG

//
// Function declarations
//
int romanToInt(char * s);

//
// Function definitions
//

////////////////////////////////////////////////////////////////
// @name romanToInt
// @description Convert roman numeral, string, to integer
// @input char* s - array of chars
// @output int res - integer representation of input roman numerals
////////////////////////////////////////////////////////////////
int romanToInt(char * s){
   int res = 0, strLen;

   strLen = strlen(s);

#ifdef DEBUG
   printf ("String length: %d\n", strLen);
#endif // DEBUG

   for (int i = 0; i < strLen; i++) {

      switch (s[i]) {
         case 'I':
            switch (s[i+1]) {
               case 'V':
               case 'X':
                  res -= 1;
                  break;
               default:
                  res += 1;
                  break;
            }
            break;
         case 'V':
            res += 5;
            break;
         case 'X':
            switch (s[i+1]) {
               case 'L':
               case 'C':
                  res -= 10;
                  break;
               default:
                  res += 10;
                  break;
            }
            break;
         case 'L':
            res += 50;
            break;
         case 'C':
            switch (s[i+1]) {
               case 'D':
               case 'M':
                  res -= 100;
                  break;
               default:
                  res += 100;
                  break;
            }
            break;
         case 'D':
            res += 500;
            break;
         case 'M':
            res += 1000;
            break;
         default:
            res = -1;
            break;
      }
   }

   return res;
}

int main() {
   char input[] = "MCMXCIV";
   int res = 0;

   res = romanToInt(&input[0]);

#ifdef DEBUG
   printf ("Result: %d\n", res);
#endif //DEBUG
   return 0;
}