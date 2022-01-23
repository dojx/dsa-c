#include <stdio.h>
#include "linked_list.h"
#include "queue_list.h"

int main() {
    Queue *q = create_queue(0);
    for(int i = 1; i <= 5; i++) {
        push(q, i);
    }
    print_q(q);
    printf("Popped: %d\n", pop(q));
    print_q(q);
    printf("Popped: %d\n", pop(q));
    print_q(q);
    for(int i = 6; i <= 9; i++) {
        push(q, i);
    }
    print_q(q);
    printf("Popped: %d\n", pop(q));
    print_q(q);
    delete_q(&q);
    return 0;
}