/*
 * Created by edfcsx on 05/08/2023.
 * Stack - Stack implementa uma pilha no padrão LIFO (Last in first out)
 */


#ifndef ESTRUTURAS_DE_DADOS_EM_C_STACK_H
#define ESTRUTURAS_DE_DADOS_EM_C_STACK_H

#include "types.h"

typedef struct
{
    uint data;
    struct UINT_StackItem * next;
} UINT_StackItem;

typedef struct {
    uint size;
    UINT_StackItem * items;
} UINT_Stack;

UINT_Stack UINT_MakeStack();
void UINT_StackPrint(const UINT_Stack * src);
void UINT_StackPush(uint data, UINT_Stack * dest);
void UINT_StackClear(UINT_Stack * src);
uint UINT_StackPop(UINT_Stack * src);


#endif //ESTRUTURAS_DE_DADOS_EM_C_STACK_H
