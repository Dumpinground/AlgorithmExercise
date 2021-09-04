//
// Created by hasee on 2021/9/4.
//

#ifndef ALGORITHMEXERCISE_TYPEELEMENT_H
#define ALGORITHMEXERCISE_TYPEELEMENT_H

#include <ostream>

typedef int ElemType;

#define MaxSize 50

struct LNode {
    ElemType data;
    LNode *next;
};

struct DNode{
    ElemType data;
    struct DNode *prior, *next;
};

std::ostream &operator<<(std::ostream &out, LNode N);
std::ostream &operator<<(std::ostream &out, DNode D);

#endif //ALGORITHMEXERCISE_TYPEELEMENT_H
