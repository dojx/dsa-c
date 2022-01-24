#ifndef QUEUE_LIST_H
#define QUEUE_LIST_H

#include "linked_list.h"

typedef struct Queue {
    int size;
    Node *head, *tail;
} Queue;

Queue* create_queue(int x);
void print_q(Queue *q);
void push(Queue *q, int x);
int pop(Queue *q);
void delete_q(Queue **q);

#endif