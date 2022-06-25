#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>
#include <assert.h>

#define DEBUG
#define MAX_STR_LEN           (10000)
#define PARENTHESIS_OPEN      ('(')
#define PARENTHESIS_CLOSED    (')')
#define BRACE_OPEN            ('{')
#define BRACE_CLOSED          ('}')
#define BRACKET_OPEN          ('[')
#define BRACKET_CLOSED        (']')
#define NULL_CHAR             ('\0')

//
// Function definitions
//

bool isChar(char s, char closedChar) {
   return (s == closedChar);
}

bool isOpenParenthesis(char s) {
   return isChar(s, PARENTHESIS_OPEN);
}

bool isOpenBrace(char s) {
   return isChar(s, BRACE_OPEN);
}

bool isOpenBracket(char s) {
   return isChar(s, BRACKET_OPEN);
}

bool isClosed(char s) {
   return (isChar(s, BRACKET_CLOSED) || isChar(s, BRACE_CLOSED) || isChar(s, PARENTHESIS_CLOSED));
}

bool isOpen(char s) {
   return (isChar(s, BRACKET_OPEN) || isChar(s, BRACE_OPEN) || isChar(s, PARENTHESIS_OPEN));
}
////////////////////////////////////////////////////////////////
// @name isValid
// @brief Check if string has correct paranthesis, brace, bracket behavior
// @input char* s          - string consisting of parenthesis, brace, and brackets
// @output bool res        - true if paired and in order, false otherwise
////////////////////////////////////////////////////////////////
bool isValid(char * s) {
   char stack[MAX_STR_LEN];
   uint32_t stackIdx = 0, charIdx = 0;
   char nextChar;

   nextChar = s[charIdx]; 


   // string must begin with open char, else return false
   if (!isOpen(nextChar)) {
      return false;
   }

   while (!isChar(nextChar, NULL_CHAR)) {
      // if a open parenthesis, brace, or bracket, push to top of stack
      if (isOpen(nextChar)) {
         stack[stackIdx] = nextChar;
         stackIdx++;

      #ifdef DEBUG
         printf ("nextChar,%c,charIdx,%d,stackIdx,%d,stack,%c,uid,%d\n", nextChar,charIdx,stackIdx,stack[stackIdx-1],0x0);
      #endif // DEBUG*/
      } else
      // if stack is empty (no open chars), next character is invalid
      if (!stackIdx) {
      #ifdef DEBUG
         printf ("nextChar,%c,charIdx,%d,stackIdx,%d,stack,%c,uid,%d\n", nextChar,charIdx,stackIdx,stack[stackIdx-1],0x1);
      #endif // DEBUG*/
         return false;
      } else {

      #ifdef DEBUG
         printf ("nextChar,%c,charIdx,%d,stackIdx,%d,stack,%c,uid,%d\n", nextChar,charIdx,stackIdx,stack[stackIdx-1],0x2);
      #endif // DEBUG*/
         // check for valid closed parenthsis, brace, or bracket and pop top of stack
         switch (nextChar) {
            case PARENTHESIS_CLOSED:
               if (isOpenParenthesis(stack[stackIdx-1])) {
                  stackIdx--;
               }
               else {
                  return false;
               }
               break;
            case BRACE_CLOSED:
               if (isOpenBrace(stack[stackIdx-1])) {
                  stackIdx--;
               }
               else {
                  return false;
               }
               break;
            case BRACKET_CLOSED:
               if (isOpenBracket(stack[stackIdx-1])) {
                  stackIdx--;
               }
               else {
                  return false;
               }
               break;
            default:
               return false;
               break;
         }
      }

      charIdx++;
      nextChar = s[charIdx];
   }

   // check if stack has remaining open chars
   if (stackIdx) {
      return false;
   } else {
      return true;
   }
}

int main() {
   char str[] = "(])";
   char *pStr;
   bool res = true;

   pStr = &str[0];

   res = isValid(pStr);

#ifdef DEBUG
   printf("String,%s,isValid,%d\n",str, res);
#endif // DEBUG
   return 0;
}