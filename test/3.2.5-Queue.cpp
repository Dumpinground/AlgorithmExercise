//
// Created by hasee on 2021/9/3.
//

#include <gtest/gtest.h>
#include <iostream>

#include "../myLib/stack/stack.h"
#include "../myLib/queue/Queue.h"

using namespace std;

TEST(Queue, 0) {
    SqQueue Q;
}

void Inverser(SqQueue &Q) {
    SqStack S;
    InitStack(S);
    int x;
    while (!QueueEmpty(Q)) {
        DeQueue(Q, x);
        Push(S, x);
    }
    while (!StackEmpty(S)) {
        Pop(S, x);
        EnQueue(Q, x);
    }
}

TEST(Queue, 2) {
    SqQueue Q;
    InitQueue(Q);
    for (int i = 0; i < 10; ++i) {
        EnQueue(Q, i);
    }
    cout << Q << endl;
    Inverser(Q);
    cout << Q << endl;
}

struct MyQueue {
    SqStack S1, S2;
    MyQueue() {
        InitStack(S1);
        InitStack(S2);
    }

    bool Enqueue(int &x) {
        while (!StackEmpty(S2)) {
            int y;
            Pop(S2, y);
            Push(S1, y);
        }
        if (StackOverflow(S1))
            return false;
        Push(S1, x);
        return true;
    }

    bool Dequeue(int &x) {
        while (!StackEmpty(S1)) {
            int y;
            Pop(S1, y);
            Push(S2, y);
        }
        if (StackEmpty(S2))
            return false;
        Pop(S2, x);
        return true;
    }

    bool QueueEmpty() const {
        return StackEmpty(S1) && StackEmpty(S2);
    }

    friend ostream &operator<<(ostream &out, MyQueue &Q) {
        int x;
        while (!Q.QueueEmpty()) {
            Q.Dequeue(x);
            out << " " << x;
        }
        out << endl;
        return out;
    }
};

struct MyQueue2 {
    LNode *front, *rear;
    MyQueue2() {
        front = rear = (LNode*) malloc(sizeof(LNode));
        rear->next = front;
    }

    bool Empty() {
        return front == rear;
    }

    bool Overflow() {
        return rear->next == front;
    }

    void En(ElemType &x) {
        if (Overflow()) {
            LNode *n = (LNode*) malloc(sizeof(LNode));
            n->data = x;
            n->next = rear->next;
            rear->next = n;
            rear = n;
        } else {
            rear->data = x;
            rear = rear->next;
        }
    }

    bool De(ElemType &x) {
        if (Empty())
            return false;
        x = front->data;
        front = front->next;
    }
};

TEST(Queue, 3) {
    MyQueue Q;
    for (int i = 0; i < 10; ++i) {
        Q.Enqueue(i);
    }
    cout << Q << endl;
}



TEST(Queue, 4) {

}
