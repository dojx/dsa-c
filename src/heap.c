#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "heap.h"

Heap* create_heap(int x, bool is_max_heap) {
    Heap *heap = (Heap*) malloc(sizeof(Heap));
    heap->capacity = 4;
    heap->data = (int*) calloc(heap->capacity, sizeof(int));
    heap->data[0] = x;
    heap->size = 1;
    heap->is_max_heap = is_max_heap;
    return heap;
}

void insert(Heap *heap, int x) {
    if(heap->size == heap->capacity) {
        heap->capacity *= 2;
        heap->data = (int*) realloc(heap->data, sizeof(int) * heap->capacity);
    } 
    bubble_up(heap, x);
    heap->size++;
}

void delete_by_val(Heap *heap, int x) {
    for(int i = 0; i < heap->size; i++) {
        if(x == heap->data[i]) {
            swap(&(heap->data[i]), &(heap->data[heap->size - 1]));  
            heap->data[heap->size - 1] = 0;          
            bubble_down(heap, i);
            heap->size--;
            return;
        }
    }
}

void print_heap(Heap *heap) {
    for (int i = 0; i < heap->size; i++) {
        printf("(%d)", heap->data[i]);
    }
    printf("\n");
}

void bubble_up(Heap *heap, int x) {
    int idx = heap->size;
    heap->data[idx] = x;

    while(idx != 0 && heap->data[idx] < heap->data[(idx - 1) / 2]) {
        swap(&(heap->data[idx]), &(heap->data[(idx - 1) / 2]));
        idx = (idx - 1) / 2;
    }
}

void bubble_down(Heap *heap, int curr_idx) {
    int lc_idx = (curr_idx * 2) + 1, rc_idx = (curr_idx * 2) + 2;
    while(curr_idx < heap->size) {
        if(heap->data[lc_idx] && heap->data[curr_idx] > heap->data[lc_idx]) {
            swap(&(heap->data[curr_idx]), &(heap->data[lc_idx]));
        } else if(heap->data[rc_idx] && heap->data[curr_idx] > heap->data[rc_idx]) {
            swap(&(heap->data[curr_idx]), &(heap->data[rc_idx]));
        } else {
            return;
        }
    }
}

void swap(int *a, int *b) {
    int c = *a;
    *a = *b;
    *b = c;
}

int pop_root(Heap *heap) {
    int data = heap->data[0];
    delete_by_val(heap, data);
    return data;
}

void delete_heap(Heap **heap) {
    free((*heap)->data);
    free(*heap);
    *heap = NULL;
}