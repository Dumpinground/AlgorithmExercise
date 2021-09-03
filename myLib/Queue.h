//
// Created by hasee on 2021/9/3.
//

#ifndef ALGORITHMEXERCISE_QUEUE_H
#define ALGORITHMEXERCISE_QUEUE_H

typedef int ElemType;

#define MaxSize 50

struct SqQueue {
    ElemType data[MaxSize];
    int front, rear;
};

void InitQueue(SqQueue &Q);
void DestroyQueue(SqQueue &Q);

bool QueueEmpty(SqQueue Q);

bool EnQueue(SqQueue &Q, ElemType x);
bool DeQueue(SqQueue &Q, ElemType &x);

bool GetHead(SqQueue &Q, ElemType &x);

#endif //ALGORITHMEXERCISE_QUEUE_H
