//
// Created by hasee on 2021/8/15.
//

#include <gtest/gtest.h>

#define ElemType int

#include "../myLib/stack.h"
//#include "../myLib/list/LinkedList.h"

using namespace std;

TEST(Stack, testSqStack) {
    SqStack S;
    int e;
    InitStack(S);
    cout << "Empty: " << StackEmpty(S) << endl;
    for (int i = 0; i < 10; ++i) {
        Push(S, i);
    }
    cout << S << endl;
    Pop(S, e);
    cout << S << endl;
    cout << "Top: " << S.top << " Empty: " << StackEmpty(S) << endl;
}

TEST(Stack, testLiStack) {
    LiStack S;
    int e;
    InitStack(S);
    cout << "Empty: " << StackEmpty(S) << endl;
    for (int i = 0; i < 10; ++i) {
        Push(S, i);
    }
    cout << S << endl;
    Pop(S, e);
    cout << S << endl;
    GetTop(S, e);
    cout << "Top: " << e << " Empty: " << StackEmpty(S) << endl;
}

bool isLegal(char a[]) {
    int stackSize = 0;
    for (int i = 0; i < strlen(a); ++i) {
        switch (a[i]) {
            case 'I':
                stackSize++;
                break;
            case 'O':
                stackSize--;
        }
        if (stackSize < 0)
            return false;
    }
    return stackSize == 0;
}

TEST(Stack, 3) {
    char a[] = "IOIIOIOO", b[] = "IOOIOIIO", c[] = "IIIOIOIO", d[] = "IIIOOIOO";
    cout << isLegal(a) << " " << isLegal(b) << " " << isLegal(c) << " " << isLegal(d) << endl;
}

#undef ElemType
//#define ElemType string

#include "../myLib/list/LinkedList.h"

bool isCentrosymmetric(LinkedList L) {
    LNode *p = L;
    while (p) {
        ElemType data = p->data;
        string text = to_string(data).data();
        cout << text << endl;

        int len = text.length();
        SqStack S;
        InitStack(S);

        for (int i = 0; i < len; ++i) {
            int d, x;

            if (i < len / 2) {
                Push(S, d);
            } else {
                Pop(S, x);
                if (x != d)
                    return false;
            }
        }

        p = p->next;
    }

    return true;
}

TEST(Stack, 4) {
    LinkedList L;
    InitList(L);
//    List_TailInsert(L, {"xx", "sys", "wertty", "yuuif0", "54fgLgf45"});
    List_TailInsert(L, {121, 223, 421, 56965, 344443, 10312});
//    cout << L << endl;
    isCentrosymmetric(L->next);
}

TEST(Stack, 5) {

}
