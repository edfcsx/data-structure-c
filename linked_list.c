//
// Created by edfcsx on 06/08/2023.
//

#include "linked_list.h"


UINT_LinkedList UINT_MakeLinkedList()
{
    UINT_LinkedList temp;
    temp.size = 0;
    temp.items = NULL;

    return temp;
}

void UINT_LinkedListAdd(uint data, UINT_LinkedList * dest)
{
    UINT_LinkedListItem * node = (UINT_LinkedListItem*) calloc(1, sizeof(UINT_LinkedListItem));
    node->data = data;
    node->next = NULL;

    if (!dest->size)
    {
        dest->items = node;
        dest->size = dest->size + 1;
        return;
    }

    UINT_LinkedListItem * it = (UINT_LinkedListItem*) dest->items;

    while (it->next != NULL)
        it = (UINT_LinkedListItem*) it->next;

    it->next = (struct UINT_LinkedListItem *) node;
    dest->size = dest->size + 1;
}

void UINT_LinkedListPrint(const UINT_LinkedList * src)
{
    if (!src->size)
        printf("This list is empty");
    else
    {
        UINT_LinkedListItem * it = src->items;
        while (it)
        {
            printf("%d\n", it->data);
            it = (UINT_LinkedListItem *) it->next;
        }
    }
}

uint UINT_LinkedListRemove(uint data, UINT_LinkedList * src)
{
    if (src->size == 1)
    {
        free(src->items);
        src->items = NULL;
        src->size = 0;

        return 1;
    }

    UINT_LinkedListItem * current = src->items;
    UINT_LinkedListItem * prev = NULL;

    while (current != NULL)
    {
        if (current->data == data)
        {
            if (prev == NULL)
            {
                UINT_LinkedListItem * junk = src->items;
                src->items = (UINT_LinkedListItem*) junk->next;
                free(junk);
                src->size = src->size - 1;
                return 1;
            }

            if (current->next == NULL)
            {
                prev->next = NULL;
                free(current);
                src->size = src->size - 1;
                return 1;
            }

            UINT_LinkedListItem * junk = (UINT_LinkedListItem*) prev->next;
            prev->next = current->next;
            src->size = src->size - 1;
            free(junk);
            return 1;
        }

        prev = current;
        current = (UINT_LinkedListItem*) current->next;
    }

    return 0;
}

void UINT_LinkedListClear(UINT_LinkedList * src)
{
    if (src->size > 0)
    {
        src->size = 0;
        UINT_LinkedListItem * it = src->items;

        while (it != NULL)
        {
            UINT_LinkedListItem * tmp = (UINT_LinkedListItem*) it->next;
            free(it);
            it = tmp;
        }
    }
}