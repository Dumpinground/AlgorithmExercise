//
// Created by hasee on 2021/8/15.
//

#ifndef ALGORITHMEXERCISE_STACK_H
#define ALGORITHMEXERCISE_STACK_H

#define MaxSize 10

typedef int Elemtype;

//顺序栈
struct SqStack {
    Elemtype data[MaxSize];
    int top;
};

//共享栈
struct ShStack {
    Elemtype x;
    int top0, top1;
};

void InitStack(SqStack &S) {
    S.top = -1;
}

void InitStack(ShStack &S) {
    S.top0 = -1; //从底部开始
    S.top1 = MaxSize; //从顶部开始
}

void DestroyStack(SqStack &S);

bool Push(SqStack &S, Elemtype x) {

    if (S.top == MaxSize - 1)
        return false;

//    S.top++;
//    S.data[S.top] = x;
    S.data[++S.top] = x;
    return true;
}

bool Pop(SqStack &S, Elemtype &x) {

    if (S.top == -1)
        return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, Elemtype &x) {
    if (S.top == -1)
        return false;
    x = S.data[S.top];
    return true;
}

bool StackEmpty(SqStack S) {
    return S.top == -1;
}

#endif //ALGORITHMEXERCISE_STACK_H
