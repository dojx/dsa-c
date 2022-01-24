#ifndef STACK_H
#define STACH_H

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

typedef struct Stack {
    int size;
    Node *base, *top;
} Stack;

Stack* create_stack(int x);
void push_s(Stack *s, int x);
int pop_s(Stack *s);
void delete_stack(Stack **s);
void print_stack(Stack *s);

#endif