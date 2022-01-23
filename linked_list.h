#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* create_node(int x);
void add_tail(Node *head, int x);
void add_head(Node **head, int x);
void delete_list(Node **head);
void print_list(Node *head);
void print_reverse_recursive(Node *head);
void reverse_list_it(Node **head);
Node* reverse_list_re(Node **head, Node *curr);

#endif