//
// Created by hasee on 2021/6/27.
//

#include <gtest/gtest.h>
#include "../myLib/LinkedList.h"
#include "../myLib/DLinkedList.h"
#include "../myLib/StaticList.h"

using namespace std;

TEST(LinkedList, 0) {
    cout << "2.3.7 Linked List" << endl;
}

LinkedList ListCreat(const vector<ElemType>& data = {1, 2, 3, 4, 5}, bool reverse = false) {

    LinkedList list;
    InitList(list);

    if (reverse)
        List_HeadInsert(list, data);
    else
        List_TailInsert(list, data);

    return list;
}

TEST(LinkedList, testHeadInsert) {
    vector<int> data = {1, 2, 3, 4, 5};
    cout << ListCreat(data, true) << endl;
}

TEST(LinkedList, testTailInsert) {
    cout << ListCreat() << endl;
}

TEST(LinkedList, testGetElem) {
    auto list = ListCreat();
    cout << *GetElem(list, 5) << endl;
}

TEST(LinkedList, testLocateElem) {
    auto list = ListCreat();
    cout << *LocateElem(list, 3) << endl;
}

TEST(LinkedList, testInsert) {
    auto list = ListCreat();

    cout << ListInsert(list, 0, 100) << endl;
    cout << ListInsert(list, 6, 100) << endl;

    ListInsert(list, 3, 100);
    cout << list << endl;
}

TEST(LinkedList, testInsertNext) {
    auto list = ListCreat();
    LNode *n = GetElem(list, 3);
    InsertNextNode(n, 100);
    cout << list << endl;
}

TEST(LinkedList, testInsertPrior) {
    auto list = ListCreat();
    LNode *n = GetElem(list, 3);
    InsertPriorNode(n, 100);
    cout << list << endl;
}

TEST(LinkedList, testDelete) {
    auto list = ListCreat();
    int e;
    ListDelete(list, 3, e);
    cout << list << endl << e << endl;
    ListDelete(list, 4, e);
    cout << list << endl << e << endl;
    cout << ListDelete(list, 4, e) << endl;
}

TEST(LinkedList, testDeleteNode) {
    auto list = ListCreat();
    int e;
    LNode *m = GetElem(list, 4), *n;
    DeleteNode(m);
    cout << list << endl;
    n = GetElem(list, 4);
    DeleteNode(n);
    cout << list << endl;
}

TEST(DLinkedList, testDLinkedList) {
    DLinkedList L;
    InitDLinkedList(L);
    cout << empty(L) << endl;
}

TEST(DLinkedList, testDestroy) {
    DLinkedList L;
    InitDLinkedList(L);
    int e = 0;
    DNode *p = L;
    while (e++ < 5) {
        DNode *n = (DNode *) malloc(sizeof(DNode));
        n->data = e;
        InsertNextDNode(p, n);
        p = n;
    }
    cout << L << endl;
    DestroyList(L);
}

TEST(StaticList, testList) {
    Node x;
    printf("sizeX=%d\n", sizeof(x));

    Node a[MaxSize];
    printf("sizeA=%d\n", sizeof(a));

    SLinkedList b;
    printf("sizeB=%d\n", sizeof(b));
}

TEST(StaticList, ListInsert) {
    SLinkedList L;
    InitList(L);
    for (int i = 1; i <= 5; ++i) {
        ListInsert(L, i, 100 + i);
    }
    cout << L << endl;
    ListInsert(L, 3, 200);
    cout << L << endl;
    ListDelete(L, 4);
    cout << L << endl;
}

TEST(LinkedList, 1) {

}