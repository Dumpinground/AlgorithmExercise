//
// Created by hasee on 2021/9/3.
//

#include "stack.h"

void InitStack(SqStack &S) {
    S.top = -1;
}

void InitStack(ShStack &S) {
    S.top0 = -1; //从底部开始
    S.top1 = MaxSize; //从顶部开始
}

void InitStack(LiStack &S) {
    S = (LinkNode *) malloc(sizeof(LinkNode));
    S->next = NULL;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

bool StackEmpty(LiStack S) {
    return S->next == NULL;
}

void DestroyStack(SqStack &S);

bool Push(SqStack &S, ElemType x) {

    if (S.top == MaxSize - 1)
        return false;

    //    S.top++;
    //    S.data[S.top] = x;
    S.data[++S.top] = x;
    return true;
}

bool Push(LiStack &S, ElemType x) {
    LinkNode *n = (LinkNode *) malloc(sizeof(LinkNode));
    if (!n)
        return false;
    n->data = x;
    n->next = S->next;
    S->next = n;
    return true;
}

bool Pop(SqStack &S, ElemType &x) {

    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool Pop(LiStack &S, ElemType &x) {

    if (StackEmpty(S))
        return false;

    LinkNode *n = S->next;
    x = n->data;
    S->next = n->next;
    free(n);
    return true;
}

bool GetTop(SqStack S, ElemType &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

bool GetTop(LiStack S, ElemType &x) {

    if (StackEmpty(S))
        return false;

    x = S->next->data;
    return true;
}

std::ostream &operator<<(std::ostream &out, SqStack S) {
    ElemType x;
    out << "SqStack:" << std::endl;
    while (S.top != -1) {
        Pop(S, x);
        out << x << std::endl;
    }
    return out;
}

std::ostream &operator<<(std::ostream &out, LiStack S) {
    LinkNode *n = S;
    out << "LiStack:" << std::endl;
    while (n->next) {
        n = n->next;
        out << n->data << std::endl;
    }
    return out;
}