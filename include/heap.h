#ifndef HEAP_H
#define HEAP_H

typedef struct Heap {
    int size;
    int capacity;
    bool is_max_heap;
    int *data;
} Heap;

Heap* create_heap(int x, bool is_max_heap);
void insert(Heap *heap, int x);
void delete_by_val(Heap *heap, int x);
void print_heap(Heap *heap);
void bubble_up(Heap *heap, int x);
void bubble_down(Heap *heap, int idx);
void swap(int *a, int *b);
int pop_root(Heap* heap);
void delete_heap(Heap **heap);

#endif