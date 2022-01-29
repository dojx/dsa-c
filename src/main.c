#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int main() {
    Heap *heap = create_heap(8, false);

    insert(heap, 1);
    insert(heap, 7);
    insert(heap, 6);
    insert(heap, 5);
    insert(heap, 9);
    insert(heap, 4);

    print_heap(heap);

    while(heap->size) {
        printf("(%d)", pop_root(heap));
    }

    delete_heap(&heap);

    return 0;
}