/* ============================================================================
 * Christopher Boyd / Lab 04 / 29 March 2020
 * ----------------------------------------------------------------------------
 * Queue
 * Implementation details for queue
 * NOTE: Uses some boilerplate code from:
 *	codescope.com, making linked list queues in C
 *-------------------------------------------------------------------------- */

#include "queue.h"

void initialize(queue *q, int buffer)
{
  q->buf_size = buffer;
  q->count = 0;
  q->front = NULL;
  q->back = NULL;
} // end initialize

void enqueue(queue *qObj, int value)
{
  // Do not enqueue if buffer is full
  if (qObj->count < qObj->buf_size)
  {
    // Create temporary node to fill back of queue
    node *temp;
    temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->data = value;

    // Chceck if queue is empty
    if (qObj->back == NULL)
    {
      // queue empty, add first node
      qObj->front = temp;
      qObj->back = temp;
    }
    else
    {
      // Queue already populated, add node to back
      // Order below is IMPORTANT
      qObj->back->next = temp;
      qObj->back = temp;
    }

    qObj->count++;
  }
} // end enqueue

int dequeue(queue *qObj)
{
  int val = qObj->front->data;
  node *temp;

  // Set second-oldest node to front of queue
  temp = qObj->front;
  qObj->front = qObj->front->next;
  qObj->count--;
  free(temp);

  return val;
} // end dequeue

bool traverse(queue *qObj, int value)
{
  bool in_queue = false;
  node *temp = qObj->front;

  // No nodes attached yet. Can't run this logic.
  // Assume in_queue MUST be false.

    while (temp != NULL)
    {
      if (node_peek(temp) == value && qObj->count > 1)
      {    
        /* printf("======================\n");
        printf("FOUND MATCH\n");
        printf("======================\n"); */
        in_queue = true;
        break;
      }
        temp = temp->next;
    }

  return in_queue;
} // end traverse

int check_size(queue *qObj)
{
  return qObj->count;
} // end check_size
