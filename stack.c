//
// Created by edfcsx on 06/08/2023.
//

#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

UINT_Stack UINT_MakeStack()
{
    UINT_Stack tmp;
    tmp.size = 0;
    tmp.items = NULL;

    return tmp;
}

void UINT_StackPrint(const UINT_Stack * src)
{
    if (!src->size)
        printf("This stack is empty");
    else
    {
        UINT_StackItem * it = src->items;
        while (it)
        {
            printf("%d\n", it->data);
            it = (UINT_StackItem*) it->next;
        }
    }
}

void UINT_StackPush(uint data, UINT_Stack * dest)
{
    UINT_StackItem * node = (UINT_StackItem *) calloc(1, sizeof(UINT_StackItem));
    node->data = data;
    node->next = NULL;

    if (!dest->size)
    {
        dest->items = node;
        dest->size = dest->size + 1;
        return;
    }

    UINT_StackItem * it = dest->items;

    while (it->next != NULL)
        it = (UINT_StackItem*) it->next;

    it->next = (struct UINT_StackItem *) node;
    dest->size = dest->size + 1;
}

void UINT_StackClear(UINT_Stack * src)
{
    if (src->size)
    {
        src->size = 0;
        UINT_StackItem * it = src->items;

        while (it != NULL)
        {
            UINT_StackItem * tmp = (UINT_StackItem*) it->next;
            free(it);
            it = tmp;
        }
    }
}

uint UINT_StackPop(UINT_Stack * src)
{
    if (!src->size)
        return 0;

    if (src->size == 1)
    {
        uint tmp = src->items->data;
        free(src->items);
        src->size = 0;
        src->items = NULL;
        return tmp;
    }

    UINT_StackItem * prev = NULL;
    UINT_StackItem * current = src->items;

    while (current->next != NULL)
    {
        prev = current;
        current = (UINT_StackItem*) current->next;
    }

    uint tmp = current->data;
    prev->next = NULL;
    free(current);
    src->size = src->size - 1;

    return tmp;
}


