#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1


int balancedStringSplit(char * s){
   int balancedStrCntr = 0;
   int unbalancedStrCntr = 0;
   int rValue = 0;
   int i = 0;

   // scan every letter of string s
   while (s[i] != '\0') {
      // initialize if R is +1 or -1
      if (rValue == 0) {
         if (s[i] == 'R') {
            rValue = 1;
         }
         else {
            rValue = -1;
         }
      }

      // increment cntr based on char
      if (s[i] == 'R') {
         unbalancedStrCntr += rValue;
      }
      else {
         unbalancedStrCntr -= rValue;
      }

      // increment cntr based on bal cntr
      if (unbalancedStrCntr == 0) {
         balancedStrCntr += 1;
         rValue = 0;
      }

      // increment string index
      i += 1;

      if (DEBUG) {
         printf ("Unbal Cntr: %d\n", unbalancedStrCntr);
         printf (" Bal cntr: %d\n", balancedStrCntr);
         printf ("R val: %d\n", rValue);
      }
   }

   return balancedStrCntr;
}

int main() {
   char s[] = "LLLLRRRR";
   int balancedStrCntr = 0;

   balancedStrCntr = balancedStringSplit(s);

   if (DEBUG) {
      printf ("Cntr: %d\n", balancedStrCntr);
   }

   return 0;
}