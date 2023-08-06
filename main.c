#include <stdio.h>

#include "linked_list.h"
#include "stack.h"
#include "queue.h"

void example_linked_list();
void example_stack();
void example_queue();

int main(void)
{
    example_queue();
    return 0;
}

void example_linked_list()
{
    UINT_LinkedList nums = UINT_MakeLinkedList();
    UINT_LinkedListAdd(3, &nums);
    UINT_LinkedListAdd(13, &nums);
    UINT_LinkedListAdd(14, &nums);
    UINT_LinkedListAdd(42, &nums);
    UINT_LinkedListAdd(43, &nums);
    UINT_LinkedListAdd(44, &nums);

    UINT_LinkedListRemove(44, &nums);
    UINT_LinkedListClear(&nums);
}

void example_stack()
{
    // empilhando dados
    UINT_Stack stack = UINT_MakeStack();
    UINT_StackPush(1, &stack);
    UINT_StackPush(2, &stack);
    UINT_StackPush(3, &stack);
    UINT_StackPush(4, &stack);
    UINT_StackPush(5, &stack);
    UINT_StackPush(6, &stack);

    // desempilhando dados
    while (stack.size)
    {
        uint tmp = UINT_StackPop(&stack);
        printf("%d\n", tmp);
    }

    UINT_StackClear(&stack);
}

void example_queue()
{
    UINT_Queue queue = UINT_MakeQueue();
    UINT_QueuePush(1, &queue);
    UINT_QueuePush(2, &queue);
    uint tmp = UINT_QueueDequeue(&queue);
    UINT_QueuePrint(&queue);
    UINT_QueueClear(&queue);
    UINT_QueuePrint(&queue);
}