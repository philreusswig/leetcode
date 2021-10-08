#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEBUG 1

int countMatches(char *** items, int itemsSize, int* itemsColSize, char * ruleKey, char * ruleValue){
   int matchesCnt = 0;
   int keyIndex;

   for (int i = 0; i < itemsSize; i++) {
      if (!strcmp(ruleKey, "type")) {
         keyIndex = 0;
      }
      else if (!strcmp(ruleKey, "color")) {
         keyIndex = 1;
      }
      else if (!strcmp(ruleKey, "name")) {
         keyIndex = 2;
      }
      else {
         keyIndex = -1;
      }

      if (keyIndex >= 0) {
         if (!strcmp(items[i][keyIndex], ruleValue)) {
            matchesCnt += 1;
         }
      }

      if (DEBUG) {
         printf ("Key Index: %d\n", keyIndex);
         printf ("Matches: %d\n", matchesCnt);
      }
   }

   return matchesCnt;
}

int main() {
   char items[3][3][10] = {
                              {"phone","blue","pixel"},
                              {"computer","silver","lenovo"},
                              {"phone","gold","iphone"}
   };

   int i,j,k,x=3,y=3,z=10;
   char ***pItems = (char***)malloc(sizeof(char**) * x);
   for (i = 0; i < x; i++) {
      pItems[i] = (char**)malloc(sizeof(char*) * y);
      for (j = 0; j < y; j++) {
         pItems[i][j] = (char*)malloc(z);
      }
   }

   for (i = 0; i < x; i++) {
      for (j = 0; j < y; j++) {
         pItems[i][j] = &items[i][j][0];
      }
   }

   char ruleKey[] = "color";
   char ruleValue[] = "silver";
   int itemsSize = 3;
   int itemsColSize = 3;
   int matches = 0;

   matches = countMatches(pItems, itemsSize, &itemsColSize, ruleKey, ruleValue);

   if (DEBUG) {
      printf ("Number of matches: %d\n", matches);
   }

   return 0;
}