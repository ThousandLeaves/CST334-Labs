/* ============================================================================
 * Christopher Boyd / Lab 04 / 29 March 2020
 * ----------------------------------------------------------------------------
 * Queue Header
 * Contains header information for queue.h
 * NOTE: Uses some boilerplate code from:
 *	codescope.com, making linked list queues in C
 *-------------------------------------------------------------------------- */

#include "node.h"
#include <stdbool.h>

 typedef struct queue
 {
   int buf_size;
   int count;
   node *front;
   node *back;

 } queue;

// Set default values for new, empty queue object
void initialize(queue *q, int buffer);

// Add new node to the back of queue
void enqueue(queue *qObj, int value);

// Remove front (oldest) node from queue and return data
// If data returned, assume a page fault
int dequeue(queue *qObj);

// Loop function seeks if value is contained in queue.
// If not, return false.
bool traverse(queue *qObj, int value);

// Gets current size of the queue
int check_size(queue *qObj);
