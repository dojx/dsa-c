#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

Node* create_node(int x) { 
    Node *node = (Node*) malloc(sizeof(Node));
    node->data = x;
    node->next = NULL;
    return node;
}

void add_tail(Node *head, int x) {
    while(head->next != NULL) {
        head = head->next;
    }
    head->next = create_node(x);
}

void add_head(Node **head, int x) {
    Node *new_node = create_node(x);
    new_node->next = *head;
    *head = new_node;
}

void delete_list(Node **head) {
    Node *curr = *head, *next = NULL;
    while(curr != NULL) {
        next = curr->next;
        free(curr);
        curr = next;
    }
    *head = NULL;
}

void print_list(Node *head) {
    if(head == NULL) return;
    printf("Forward: ");
    while(head->next != NULL) {
        printf("(%d)-", head->data);
        head = head->next;
    }
    printf("(%d)\n", head->data);
}

void print_reverse_recursive(Node *head) {
    if(head == NULL) return;
    printf("Reverse: ");
    print_reverse_recursive(head->next);
    printf("(%d)-", head->data);
}

void reverse_list_it(Node **head) {
    Node *curr = *head, *next = NULL, *prev = NULL;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

Node* reverse_list_re(Node **head, Node *curr) {
    if(curr->next == NULL) {
        *head = curr;
        return curr;
    }
    Node *prev = reverse_list_re(head, curr->next);
    prev->next = curr;
    curr->next = NULL;
    return curr;
}