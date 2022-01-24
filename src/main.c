#include <stdio.h>
// #include "linked_list.h"
// #include "queue_list.h"
#include "stack_list.h"

int main() {
    Stack *s = create_stack(0);
    for(int i = 1; i <= 5; i++) {
        push_s(s, i);
    }
    print_stack(s);
    printf("%d\n", pop_s(s));
    delete_stack(&s);
    return 0;
}