//
// Created by hasee on 2021/8/7.
//

#ifndef ALGORITHMEXERCISE_LISTNODE_H
#define ALGORITHMEXERCISE_LISTNODE_H

typedef struct LNode {
    ElemType data;
    LNode *next;
} *LinkedList;

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
} *DLinkedList;

#endif //ALGORITHMEXERCISE_LISTNODE_H
