#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG

int finalValueAfterOperations(char ** operations, int operationsSize);
bool charIsMinusSign(char input);
bool charIsPlusSign(char input);

int main() {
   char operations[5][3] = {"--X", "X++", "X++", "X++", "X++"};
   int operationsSize = 5;
   char ** pOperations;
   int res = 0;

   pOperations = (char **)malloc(sizeof(char*));
   for (int i = 0; i < operationsSize; i++) {
      pOperations[i] = (char *)malloc(sizeof(char) * 4);
      pOperations[i] = &operations[i][0];
   }
   res = finalValueAfterOperations(pOperations, operationsSize);

   printf("Res: %d\n", res);
   return 0;
}

bool charIsMinusSign(char input) {
   return (input == '-'?true:false);
}

bool charIsPlusSign(char input) {
   return (input == '+'?true:false);
}

int finalValueAfterOperations(char ** operations, int operationsSize) {
   int res = 0;

   for (int i = 0; i < operationsSize; i++) {
      if (charIsMinusSign(operations[i][1])) {
         res--;
      } else 
      if (charIsPlusSign(operations[i][1])) {
         res++;
      } 
   }

   return res;
}