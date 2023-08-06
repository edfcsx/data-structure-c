/*
 * Created by edfcsx on 05/08/2023.
 * linked_list - Implementa uma lista encadeada simples
 */


#ifndef ESTRUTURAS_DE_DADOS_EM_C_LINKED_LIST_H
#define ESTRUTURAS_DE_DADOS_EM_C_LINKED_LIST_H

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

typedef struct {
    uint data;
    struct UINT_LinkedListItem * next;
} UINT_LinkedListItem;

typedef struct {
    uint size;
    UINT_LinkedListItem * items;
} UINT_LinkedList;

UINT_LinkedList UINT_MakeLinkedList();
void UINT_LinkedListAdd(uint data, UINT_LinkedList * dest);
void UINT_LinkedListPrint(const UINT_LinkedList * src);
uint UINT_LinkedListRemove(uint data, UINT_LinkedList * src);
void UINT_LinkedListClear(UINT_LinkedList * src);

#endif //ESTRUTURAS_DE_DADOS_EM_C_LINKED_LIST_H
