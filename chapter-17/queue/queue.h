/** Queue头文件 */
#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdbool.h>

typedef int Item;

#define MAXQUEUE 10

typedef struct node {
  Item item;
  struct node *next;
} Node;

typedef struct queue {
  Node *front; /** 指向队列首项的指针 */
  Node *rear; /** 指向队列尾项的指针 */
  int items; /** 队列中的项数 */
} Queue;

/** init queue */
void InitializeQueue(Queue *pq);

/** queue is full or not? */
bool QueueIsFull(const Queue *pq);

/** queue is empty or not? */
bool QueueIsEmpty(const Queue *pq);

/** count of queue */
int QueueItemCount(const Queue *pq);

/** add item on queue rear */
bool EnQueue(Item item, Queue *pq);

/** delete item from queue front */
bool DeQueue(Item *pitem, Queue *pq);

/** delete all items from queue */
void EmptyQueue(Queue *pq);

#endif
