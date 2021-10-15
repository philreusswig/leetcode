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

int findTheWinner(int n, int k){
   queue q;
   int numPlyrs, cntPlyrs, res;
   bool status;

   // initialize queue to size n
   queue_init(&q, n);
   // write players (1 to n) value to queue
   for (int i = 1; i < (n+1); i++) {
      status = queue_write(&q, i);
      assert(status);
   }

   // while there is more than 1 "player" in queue, continue eliminating players
   while (q.num_entries > 1) {
      // read (k-1) % n and write back to queue
      for (int i = 0; i < ((k-1) % n); i++) {
         res = queue_read(&q);
         assert(res != QUEUE_EMPTY);
         status = queue_write(&q, res);
         assert(status);
      }
      
      // read k % n and discard from queue
      res = queue_read(&q);
      assert(res != QUEUE_EMPTY);
   }

   // read final player from queue and return
   assert(q.num_entries == 1);
   res = queue_read(&q);
   assert(res != QUEUE_EMPTY);

   queue_destroy(&q);

   return res;
}

int main() {
   int n = 5, k = 2, res = -1;

   res = findTheWinner(n, k);

#ifdef DEBUG
   printf("\nWinner: %d\n", res);
#endif

   assert(res >= 0);

   return 0;
}