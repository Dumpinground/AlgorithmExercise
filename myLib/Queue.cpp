//
// Created by hasee on 2021/9/3.
//

#include <cstdlib>
#include "Queue.h"

void InitQueue(SqQueue &Q) {
    Q.front = Q.rear = 0;
}

bool QueueEmpty(SqQueue Q) {
    return Q.front == Q.rear;
}

bool EnQueue(SqQueue &Q, ElemType x) {
    if ((Q.rear + 1) % MaxSize == Q.front)
        return false;
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MaxSize;
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;
    return true;
}

bool GetHead(SqQueue &Q, ElemType &x) {
    if (Q.rear == Q.front)
        return false;
    x = Q.data[Q.front];
    return true;
}

void InitQueue(LinkQueue &Q) {
    Q.front = Q.rear = (LinkNode*) malloc(sizeof(LinkNode));
    Q.front->next = NULL;
}

bool IsEmpty(LinkQueue Q) {
    return Q.front == Q.rear;
}

void EnQueue(LinkQueue &Q, ElemType x, bool head) {
    LinkNode *s = (LinkNode*) malloc(sizeof(LinkNode));
    s->data = x;
    s->next = NULL;
    if (!head && !Q.front) {
        Q.front = Q.rear = s;
    } else {
        Q.rear->next = s;
        Q.rear = s;
    }
}

bool DeQueue(LinkQueue &Q, ElemType &x, bool head) {
    if (Q.front == Q.rear)
        return false;
    LinkNode *p;
    if (head) {
        p = Q.front->next;
        x = p->data;
        Q.front->next = p->next;
    } else {
        p = Q.front;
        x = p->data;
        Q.front = Q.front->next;
        if (Q.rear == p)
            Q.front = Q.rear = NULL;
    }
    free(p);
    return true;
}

