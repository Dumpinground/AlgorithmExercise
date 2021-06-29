//
// Created by hasee on 2021/6/27.
//

#include <gtest/gtest.h>
#include "../myLib/LinkedList.h"

using namespace std;

TEST(LinkedList, 0) {
    cout << "2.3.4 Linked List" << endl;
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

TEST(LinkedList, 1) {

}