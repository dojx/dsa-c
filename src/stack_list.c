#include <stdio.h>
#include "stack_list.h"

Stack* create_stack(int x) {
    Stack* s = (Stack*) malloc(sizeof(Stack));
    Node *new_node = create_node(x);
    new_node->next = NULL;
    s->base = new_node;
    s->top = s->base;
    s->size = 1;
    return s;
}

void push_s(Stack *s, int x) {
    Node* new_node = create_node(x);
    s->top->next = new_node;
    s->top = new_node;
    s->size++;
}

int pop_s(Stack *s) {
    if(s->top == NULL || s->base == NULL) return -1;
    Node *temp = s->top, *curr = s->base;
    while(curr->next != temp) {
        curr = curr->next;
    }
    int data = s->top->data;
    s->top = curr;
    s->top->next = NULL;
    free(temp);
    return data;
}

void print_stack(Stack *s) {
    Node *curr = s->base;
    while(curr != s->top) {
        printf("(%d)-", curr->data);
        curr = curr->next;
    }
    printf("(%d)\n", curr->data);
    printf("Size: %d\n", s->size);
}

void delete_stack(Stack **s) {
    delete_list(&((*s)->base));
    (*s)->top = NULL;
    free(*s);
    *s = NULL;
}