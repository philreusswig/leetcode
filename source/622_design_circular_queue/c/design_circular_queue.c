#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>

#define DEBUG
#define STATUS_OK       1
#define STATUS_ERROR    0
#define QUEUE_EMPTY     -1

////////////////////////////////////////////////////////////////////////////////////////////////
// define data structures here
////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct {
   int* values;     //array
   int head;        //queue read index
   int tail;        //queue write index
   int valCnt;      //queue valid count
   int size;        //size of array/queue
} MyCircularQueue;

////////////////////////////////////////////////////////////////////////////////////////////////
// declare functions here
////////////////////////////////////////////////////////////////////////////////////////////////
bool myCircularQueueIsFull(MyCircularQueue* obj);
bool myCircularQueueIsEmpty(MyCircularQueue* obj);

////////////////////////////////////////////////////////////////////////////////////////////////
// define functions here
////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////
// initialize queue
// malloc queue and array, to be freed by caller
// @param k - size of queue
// @return MyCircularQueue*
////////////////////////////////////////////////////////////////////////////////////////////////
MyCircularQueue* myCircularQueueCreate(int k) {
   MyCircularQueue* pQ;

   pQ = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
   pQ->values = (int*) malloc(sizeof(int) * k);
   pQ->size = k;
   pQ->head = 0;
   pQ->tail = 0;
   pQ->valCnt = 0;

   return pQ;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// write to queue
// @param *obj - pointer to queue
// @param value - value to be written to queue
// @return status - STATUS_OK if value added; STATUS_ERROR if queue is full
////////////////////////////////////////////////////////////////////////////////////////////////
bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {

   if(myCircularQueueIsFull(obj)) {
      return STATUS_ERROR;
   }
   else {
      obj->values[obj->tail] = value;
      obj->valCnt++;
      obj->tail++;
      if(obj->tail == obj->size) {
         obj->tail = 0;
      }
   }

   return STATUS_OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// delete from queue
// @param *obj - pointer to queue
// @return status - STATUS_OK if value added; STATUS_ERROR if queue is empty
////////////////////////////////////////////////////////////////////////////////////////////////
bool myCircularQueueDeQueue(MyCircularQueue* obj) {
   
   if(myCircularQueueIsEmpty(obj)) {
      return STATUS_ERROR;
   }
   else {
      obj->valCnt--;
      obj->head++;
      if(obj->head == obj->size) {
         obj->head = 0;
      }
   }

   return STATUS_OK;
}

////////////////////////////////////////////////////////////////////////////////////////////////
// read front of queue
// @param *obj - pointer to queue
// @return res - value at head; -1 if queue is empty
////////////////////////////////////////////////////////////////////////////////////////////////
int myCircularQueueFront(MyCircularQueue* obj) {
   
   if(myCircularQueueIsEmpty(obj)) {
      return QUEUE_EMPTY;
   }
   else {
      return obj->values[obj->head];
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// read rear of queue
// @param *obj - pointer to queue
// @return res - value at rear; -1 if queue is empty
////////////////////////////////////////////////////////////////////////////////////////////////
int myCircularQueueRear(MyCircularQueue* obj) {
   int idx;
   if(myCircularQueueIsEmpty(obj)) {
      return QUEUE_EMPTY;
   }
   else {
      if(obj->tail == 0) {
         idx = obj->size - 1;
      }
      else {
         idx = obj->tail - 1;
      }
      return obj->values[idx];
   }
}

////////////////////////////////////////////////////////////////////////////////////////////////
// is queue empty
// @param *obj - pointer to queue
// @return status - TRUE if empty; FALSE if not empty
////////////////////////////////////////////////////////////////////////////////////////////////
bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
   return (obj->valCnt == 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// is queue full
// @param *obj - pointer to queue
// @return status - TRUE if full; FALSE if not full
////////////////////////////////////////////////////////////////////////////////////////////////
bool myCircularQueueIsFull(MyCircularQueue* obj) {
   return (obj->valCnt == obj->size);
}

////////////////////////////////////////////////////////////////////////////////////////////////
// free queue and array
// @param *obj - pointer to queue
// @return none
////////////////////////////////////////////////////////////////////////////////////////////////
void myCircularQueueFree(MyCircularQueue* obj) {
   free(obj->values);
   free(obj);
}

/**
 * Your MyCircularQueue struct will be instantiated and called as such:
 * MyCircularQueue* obj = myCircularQueueCreate(k);
 * bool param_1 = myCircularQueueEnQueue(obj, value);
 
 * bool param_2 = myCircularQueueDeQueue(obj);
 
 * int param_3 = myCircularQueueFront(obj);
 
 * int param_4 = myCircularQueueRear(obj);
 
 * bool param_5 = myCircularQueueIsEmpty(obj);
 
 * bool param_6 = myCircularQueueIsFull(obj);
 
 * myCircularQueueFree(obj);
*/

int main() {

   return 0;
}