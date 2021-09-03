//
// Created by hasee on 2021/8/15.
//

#include <gtest/gtest.h>

//#define ElemType int

#include "../myLib/stack.h"
#include "../myLib/list/LinkedList.h"

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
    for (int i = 0; i < sizeof(a) / sizeof('a'); ++i) {
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

//#undef ElemType
//#define ElemType string

//#include "../myLib/list/LinkedList.h"

//bool isCentrosymmetric(LinkedList L, int n) {
//    return true;
//}

TEST(Stack, 4) {
//    LinkedList L;
////    List_TailInsert(L, {"xx", "sys", "wertty", "yuuif0", "54fgLgf45"});
//    List_TailInsert(L, {1, 2});
//    cout << L << endl;
}
