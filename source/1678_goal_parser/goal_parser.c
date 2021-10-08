#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

char * interpret(char * command) {
   int len;
   char* ret;
   int i = 0, j = 0;

   len = strlen(command);

   ret = (char *) calloc(len+1, sizeof(char));

   while (i < len) {
      switch (command[i]) {
         case 'G':
            ret[j] = 'G';
            j += 1;
            i += 1;
            break;
         case '(':
            if (command[i+1] == ')') {
               ret[j] = 'o';
               j += 1;
               i += 2;
            }
            else {
               ret[j] = 'a';
               ret[j+1] = 'l';
               j += 2;
               i += 4;
            }
            break;
         default:
            break;
      }
   }

   return ret;
}

int main() {
   char command[] = "G()()()()(al)";
   char* interpretted;

   interpretted = interpret(command);

   if (DEBUG) {
      printf ("Interpretted command: %s\n", interpretted);
   }

   free(interpretted);

   return 0;
}