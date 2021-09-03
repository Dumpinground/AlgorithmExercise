//
// Created by hasee on 2021/6/27.
//

#ifndef ALGORITHMEXERCISE_LINKEDLIST_H
#define ALGORITHMEXERCISE_LINKEDLIST_H

#include <iostream>
#include <vector>

#ifndef ElemType
typedef int ElemType;
#endif

typedef struct LNode {
    ElemType data;
    LNode *next;
} *LinkedList;

std::ostream &operator<<(std::ostream &out, LinkedList L);

std::ostream &operator<<(std::ostream &out, LNode &node);

bool InitList(LinkedList &L);

bool empty(LinkedList L);

LinkedList List_HeadInsert(LinkedList &L, const std::vector<ElemType>& values = {});

LinkedList List_TailInsert(LinkedList &L, const std::vector<ElemType>& values = {});

LNode *GetElem(LinkedList L, int i);

LNode *LocateElem(LinkedList L, ElemType e);

bool ListInsert(LinkedList L, int i, ElemType e);

bool ListDelete(LinkedList &L, int i, ElemType &e);

bool InsertNextNode(LNode *p, ElemType e);

bool InsertPriorNode(LNode *p, ElemType e);

bool DeleteNode(LNode *p);

#endif //ALGORITHMEXERCISE_LINKEDLIST_H
