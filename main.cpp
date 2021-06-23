#include <gtest/gtest.h>

#include "myLib/structure.h"

using namespace std;

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

TEST(testCase, test0) {
//    SeqList l1;
//    InitList(l1);
    std::cout << "Hello Test" << std::endl;
}

TEST(testCase, test1) {
    SeqList<int> l1;
    InitList(l1);
    ListInsert(l1, 1, 1);
    ListInsert(l1, 1, 2);
    ListInsert(l1, 1, 3);
    cout << l1 << endl;
    cout << LocateElem(l1, 2) << endl;
    int e;
    ListDelete(l1, 1, e);
    cout << l1 << endl;

    cout << GetElem(l1, 2) << endl;
}

TEST(testCase, test2) {

}
