#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define QUEUE_EMPTY NULL

typedef struct Queue
{
    char *values;
    int head, tail, num_entries, size;
} Queue;

void init_queue(Queue *q, int max_size);
bool queue_empty(Queue *q);
bool queue_full(Queue *q);
void queue_destroy(Queue *q);
bool enqueue(Queue *q, int value);
char dequeue(Queue *q);