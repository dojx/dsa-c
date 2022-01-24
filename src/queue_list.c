#include "queue_list.h"
#include <stdio.h>
#include <stdlib.h>

Queue* create_queue(int x) {
    Queue* q = (Queue*) malloc(sizeof(Queue));
    Node *new_node = create_node(x);
    new_node->next = NULL;
    q->head = new_node;
    q->tail = q->head;
    q->size = 1;
    return q;
}

void print_q(Queue *q) {
    Node* temp = q->head;
    while(temp != q->tail) {
        printf("(%d)-", temp->data);
        temp = temp->next;
    }
    printf("(%d)\n", temp->data);
    printf("Size: %d\n", q->size);
}

void push(Queue *q, int x) {
    Node* new_node = create_node(x);
    q->tail->next = new_node;
    q->tail = new_node;
    q->size++;
}

int pop(Queue *q) {
    int data = q->head->data;
    Node* temp = q->head;
    q->head = temp->next;
    q->size--;
    free(temp);
    return data;
}

void delete_q(Queue **q) {
    delete_list(&((*q)->head));
    (*q)->tail = NULL;
    free(*q);
    *q = NULL;
}