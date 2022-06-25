#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define DEBUG
#define MAX_STRS_LEN (201)             // longest string plus end of array character

//
// Function declarations
//
char * longestCommonPrefix(char ** strs, int strsSize);
//
// Function definitions
//

////////////////////////////////////////////////////////////////
// @name longestCommonPrefix
// @brief Determine the longest common prefix
// @input char** strs      - array of strings
// @input int strsSize     - length of array
// @output char* res       - longest common prefix; caller to free memory
////////////////////////////////////////////////////////////////
char * longestCommonPrefix(char ** strs, int strsSize) {
   char *res;
   char nextChar;
   uint8_t charIdx = 0;
   // allocate memory for prefix; caller will free memory;
   res = (char *)malloc(MAX_STRS_LEN*sizeof(char));

   // initialize char to compare for match in all strs
   nextChar = strs[0][charIdx];

   // keep searching until end of array
   while (nextChar != '\0') {
      // compare with all other strs
      for (uint8_t strsIdx = 1; strsIdx < strsSize; strsIdx++) {
         // if match not found, end search and exit
         if (strs[strsIdx][charIdx] != nextChar) {
            res[charIdx] = '\0';
            return res;
         }
      }
      // if match found, add char to result and advance to next char
      res[charIdx] = nextChar;
      charIdx++;
      nextChar = strs[0][charIdx];
   }
   // add end of line char to res and exit
   res[charIdx] = '\0';
   return res;
}

int main() {
   char strs[][MAX_STRS_LEN] = {"dog", "racecar", "flight"};
   char **ppStrs;
   uint8_t strsSize = 3;
   char *res;

   // dynamically create an array of pointers of size `strsSize`
   ppStrs = (char **) malloc(strsSize * sizeof(char *));
   // dynamically allocate memory of size `MAX_STRS_LEN` for each row
   for (uint8_t i = 0; i < strsSize; i++) {
      ppStrs[i] = (char *)malloc(MAX_STRS_LEN * sizeof(char));
   }
   // initialize memory
   for (uint8_t i = 0; i< strsSize; i++) {
      ppStrs[i] = &strs[i][0];
   }

#ifdef DEBUG
   for (uint8_t i = 0; i< strsSize; i++) {
      printf ("strs[%d]: %s\n", i, strs[i]);
   }
#endif // DEBUG

   // get longest common prefix
   res = longestCommonPrefix(ppStrs, strsSize);

#ifdef DEBUG
   printf ("res: %s\n", res);
#endif // DEBUG
   // release malloc memory
   free(res);
   free(ppStrs);

   return 0;
}