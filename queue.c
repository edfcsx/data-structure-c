/*
 * Created by edfcsx on 06/08/2023.
 * Queue - Implementa uma fila no padrão FIFO (First In - First Out)
 */

#include <stdlib.h>
#include "queue.h"

UINT_Queue UINT_MakeQueue()
{
    UINT_Queue tmp;
    tmp.size = 0;
    tmp.begin = NULL;
    tmp.end = NULL;

    return tmp;
}

void UINT_QueuePush(uint data, UINT_Queue * dest)
{
    UINT_QueueItem * node = (UINT_QueueItem*) calloc(1, sizeof(UINT_QueueItem*));
    node->next = NULL;
    node->data = data;

    if (!dest->size)
    {
        dest->size = 1;
        dest->begin = node;
        dest->end = node;
        return;
    }

    dest->end->next = (struct UINT_QueueItem*) node;
    dest->end = node;
    dest->size = dest->size + 1;
}

void UINT_QueuePrint(UINT_Queue * src)
{
    if (!src->size)
        printf("This queue is empty\n");
    else
    {
        UINT_QueueItem * it = src->begin;

        while (it)
        {
            printf("%d\n", it->data);
            it = (UINT_QueueItem*) it->next;
        }
    }
}

uint UINT_QueueDequeue(UINT_Queue * src)
{
    if (!src->size)
        return 0;

    if (src->size == 1)
    {
        uint tmp = src->begin->data;
        src->size = 0;
        src->begin = NULL;
        free(src->end);
        return tmp;
    }

    uint tmp = src->begin->data;
    UINT_QueueItem * junk = src->begin;
    src->begin = (UINT_QueueItem*) src->begin->next;
    free(junk);
    src->size = src->size - 1;

    return tmp;
}

void UINT_QueueClear(UINT_Queue * src)
{
    if (src->size)
    {
        UINT_QueueItem * it = src->begin;

        while (it)
        {
            UINT_QueueItem * tmp = (UINT_QueueItem*) it->next;
            free(it);
            it = tmp;
        }

        src->size = 0;
        src->begin = NULL;
        src->end = NULL;
    }
}
