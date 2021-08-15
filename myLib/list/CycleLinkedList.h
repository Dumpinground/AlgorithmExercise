//
// Created by hasee on 2021/8/7.
//

#ifndef ALGORITHMEXERCISE_CYCLELINKEDLIST_H
#define ALGORITHMEXERCISE_CYCLELINKEDLIST_H

#include "ListNode.h"

bool InitList(LinkedList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if (L == NULL)
        return false;
    L->next = L;
    return true;
}

bool Empty(LinkedList L) {
    return L->next == L;
}

bool isTail(LinkedList L, LNode *p) {
    return p->next == L;
}

#endif //ALGORITHMEXERCISE_CYCLELINKEDLIST_H
