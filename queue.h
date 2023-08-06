/*
 * Created by edfcsx on 06/08/2023.
 * Queue - Implementa uma fila no padrão FIFO (First In - First Out)
 */

#ifndef ESTRUTURAS_DE_DADOS_EM_C_QUEUE_H
#define ESTRUTURAS_DE_DADOS_EM_C_QUEUE_H

#include <stdio.h>
#include "types.h"

typedef struct {
    uint data;
    struct UINT_QueueItem * next;
} UINT_QueueItem;

typedef struct {
    uint size;
    UINT_QueueItem * begin;
    UINT_QueueItem * end;
} UINT_Queue;

UINT_Queue UINT_MakeQueue();
void UINT_QueuePush(uint data, UINT_Queue * dest);
void UINT_QueuePrint(UINT_Queue * src);
uint UINT_QueueDequeue(UINT_Queue * src);
void UINT_QueueClear(UINT_Queue * src);

#endif //ESTRUTURAS_DE_DADOS_EM_C_QUEUE_H
