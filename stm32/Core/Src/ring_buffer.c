#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "ring_buffer.h"

#define QUEUE_EMPTY NULL


void init_queue(Queue *q, int max_size)
{
    q->size = max_size;
    q->values = (char *)malloc(q->size * sizeof(char));
    q->num_entries = 0;
    q->head = 0;
    q->tail = 0;
}

bool queue_empty(Queue *q)
{
    return (q->num_entries == 0);
}

bool queue_full(Queue *q)
{
    return q->num_entries == q->size;
}

void queue_destroy(Queue *q)
{
    free(q->values);
}

bool enqueue(Queue *q, int value)
{
    if (queue_full(q))
    {
        q->num_entries = q->size - 2;
    }

    q->values[q->tail] = value;
    q->tail = (q->tail + 1) % q->size;
    q->num_entries += 1;
    return true;
}

char dequeue(Queue *q)
{
    char result;

    if (queue_empty(q))
    {
        return false;
    }

    result = q->values[q->head];
    q->head = (q->head + 1) % q->size;
    q->num_entries -= 1;

    return result;
}