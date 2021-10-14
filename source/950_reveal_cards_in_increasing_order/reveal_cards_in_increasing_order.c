#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG

#define QUEUE_EMPTY INT_MIN

////////////////////////////////////////////////////////////////////////////////////////////////
// data structures
////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct{
   int *values;        // pointer to q
   int head;           // head (read index) of queue
   int tail;           // tail (write index) of queue
   int num_entries;    // number of entries in queue
   int size;           // max size of queue
} queue;

////////////////////////////////////////////////////////////////////////////////////////////////
// initialize queue
// @param *q - pointer to queue
// @param max_size - size of queue
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void queue_init(queue *q, int max_size) {
   q->size = max_size;
   q->values = malloc(sizeof(int) * q->size);
   q->num_entries = 0; //we're empty
   q->head = 0;
   q->tail = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// is queue empty
// @param *q - pointer to queue
// @return true/false
////////////////////////////////////////////////////////////////////////////////////////////////
bool queue_isEmpty(queue* q) {
   return (q->num_entries == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// is queue full
// @param *q - pointer to queue
// @return true/false
////////////////////////////////////////////////////////////////////////////////////////////////
bool queue_isFull(queue* q) {
   return (q->num_entries == q->size);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// destroy queue
// @param *q - pointer to queue
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void queue_destroy(queue *q) {
   free(q->values);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// write to queue
// @param *q - pointer to queue
// @param value - entry to add/write to queue
// @return success/error
////////////////////////////////////////////////////////////////////////////////////////////////
bool queue_write(queue *q, int value) {

   if (queue_isFull(q)) {
      return false;
   }
   q->values[q->tail] = value;
   q->num_entries++;
   q->tail = (q->tail + 1) % q->size;

   return true;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// read from queue
// @param *q - pointer to queue
// @return result
////////////////////////////////////////////////////////////////////////////////////////////////
int queue_read(queue *q) {
   int result;

   if(queue_isEmpty(q)) {
   return QUEUE_EMPTY;
   }

   result = q->values[q->head];
   q->head = (q->head + 1) % q->size;
   q->num_entries--;

   return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// sort array in descending order
// @param *q - pointer to array
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void sortArrDec(int* deck, int deckSize) {
   int temp;

   for(int i = 0; i < deckSize; i++) {
      for(int j = i+1; j < deckSize; j++) {
         if(deck[j] > deck[i]) {
            temp = deck[i];
            deck[i] = deck[j];
            deck[j] = temp;
         }
      }
   }

#ifdef DEBUG
   for (int i = 0; i < deckSize; i++) {
      printf("Idx: %d\tVal: %d\n", i, deck[i]);
   }
   printf("\n");
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////
// copy array to queue
// @param *arr - pointer to array
// @param arrLen - length of array
// @param *q - pointer to q
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void cpyArrToQueue(int* arr, int arrLen, queue* q) {
   bool status;

   for(int i = 0; i < arrLen; i++) {
      status = queue_write(q, arr[i]);

      assert(status);

#ifdef DEBUG
      printf("Arr Idx: %d\tQ numEntries: %d\thead:%d\ttail:%d\tvalue: %d\n", i, q->num_entries, q->head, q->tail, q->values[i]);
#endif
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// copy queue to array
// @param *arr - pointer to array
// @param arrLen - length of array
// @param *q - pointer to q
// @return ok/error
////////////////////////////////////////////////////////////////////////////////////////////////
void cpyQueueToArr(queue* q, int* arr, int arrLen) {
   int result;

   for(int i = arrLen-1; i >= 0; i--) {
      result = queue_read(q);

      if(result == QUEUE_EMPTY) {
         break;
      } else {
         arr[i] = result;
      }
   }

   if(q->num_entries) {
      assert(false);
   }

#ifdef DEBUG
   for(int i = 0; i < arrLen; i++) {
      printf("Idx: %d\tVal: %d\n", i, arr[i]);
   }
#endif
}

////////////////////////////////////////////////////////////////////////////////////////////////
// sort queue/array in revealed increasing manner
// @param *qDeckAsc - pointer to queue
// @param *qDeckRevInc - pointer to q
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void sortRevealedIncreasing(queue* qDeckAsc, queue* qDeckRevInc) {
   bool status;
   int result;

   // repeat until all entries from qAsc have been written to qRevInc
   while(qDeckAsc->num_entries) {
      // step 1 read qRevInc
      result = queue_read(qDeckRevInc);

      // if qRevInc not empty, write to qRevInc
      if(result != QUEUE_EMPTY) {
         // step 2 write res to qRevInc
         status = queue_write(qDeckRevInc, result);
         assert(status);
      }

      // step 3 read qAsc
      result = queue_read(qDeckAsc);

      // step 4 write qRevInc
      status = queue_write(qDeckRevInc, result);
      assert(status);
   }

#ifdef DEBUG
   for(int i = 0; i < qDeckRevInc->num_entries; i++){
      printf("Idx: %d\tqOut num: %d\tqOut head: %d\tqOut tail: %d\tqOut val: %d\n", i, qDeckRevInc->num_entries, qDeckRevInc->head, qDeckRevInc->tail, qDeckRevInc->values[i]);
   }
#endif
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
   int* pRetArr;
   queue qDeckAsc;
   queue qDeckRevInc;

   // init queues used for sorting
   queue_init (&qDeckAsc, deckSize);
   queue_init (&qDeckRevInc, deckSize);

   // sort array in descending order
   sortArrDec(deck, deckSize);

   // copy array to queue
   cpyArrToQueue(deck, deckSize, &qDeckAsc);

   // sort array in revealed increasing
   sortRevealedIncreasing(&qDeckAsc, &qDeckRevInc);

   // define length of return array for caller
   *returnSize = deckSize;

   // allocate memory for return array. caller will free memory.
   pRetArr = (int *) malloc(sizeof(int) * deckSize);

   // copy queue to array
   cpyQueueToArr(&qDeckRevInc, pRetArr, *returnSize);

   return pRetArr;
}

int main() {
   int deck[] = {0,1,2,3,4,5};
   int deckSize = 6;
   int returnSize = 6;
   int* pRetArr;

   pRetArr = deckRevealedIncreasing(deck, deckSize, &returnSize);

#ifdef DEBUG
   // debug prints to observe contents of return array
   for (int i = 0; i < returnSize; i++) {
      printf ("Idx: %d\tVal: %d\n", i, pRetArr[i]);
   }
   printf("\n");
#endif

   // caller will free memory of return array
   free(pRetArr);

   return 0;
}