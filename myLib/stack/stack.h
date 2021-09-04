//
// Created by hasee on 2021/8/15.
//

#ifndef ALGORITHMEXERCISE_STACK_H
#define ALGORITHMEXERCISE_STACK_H

#include "../TypeElement.h"

#include <ostream>

//顺序栈
struct SqStack {
    ElemType data[MaxSize];
    int top;
};

//共享栈
struct ShStack {
    ElemType x;
    int top0, top1;
};

//链栈
typedef LNode *LiStack;

void InitStack(SqStack &S);
void InitStack(ShStack &S);
void InitStack(LiStack &S);

bool StackEmpty(SqStack S);
bool StackEmpty(LiStack S);

bool StackOverflow(SqStack S);
bool StackOverflow(ShStack S);

void DestroyStack(SqStack &S);

bool Push(SqStack &S, ElemType x);
bool Push(LiStack &S, ElemType x);

bool Pop(SqStack &S, ElemType &x);
bool Pop(LiStack &S, ElemType &x);

bool GetTop(SqStack S, ElemType &x);
bool GetTop(LiStack S, ElemType &x);

std::ostream &operator<<(std::ostream &out, SqStack S);
std::ostream &operator<<(std::ostream &out, LiStack S);

#endif //ALGORITHMEXERCISE_STACK_H
