//
// Created by hasee on 2021/8/7.
//

#ifndef ALGORITHMEXERCISE_CYCLEDLINKEDLIST_H
#define ALGORITHMEXERCISE_CYCLEDLINKEDLIST_H

#include "ListNode.h"

bool InitList(DLinkedList &L) {
    L = (DNode *)malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->next = L;
    L->prior = L;
    return true;
}

bool Empty(DLinkedList &L) {
    return (L->next == L)
}

bool isTail(DLinkedList &L, DNode *p) {
    return p->next == L;
}

#endif //ALGORITHMEXERCISE_CYCLEDLINKEDLIST_H
