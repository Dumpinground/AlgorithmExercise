//
// Created by hasee on 2021/10/31.
//

#include "../myLib/sort/Sort.h"

#include <gtest/gtest.h>
#include <iostream>
#include <functional>

using namespace std;

struct Array {
    int *data;
    int n;

    int operator[] (int i) const {
        return data[i];
    }

    friend ostream &operator<<(ostream &out, Array a) {
        for (int i = 0; i < a.n; ++i) {
            out << " " << a.data[i];
        }
        out << endl;
        return out;
    }
};

Array A = {
        new int[8] {6, 5, 4, 3, 2, 1, 0, -1},
        8
}, B = {
        new int[8] {-1, 0, 1, 2, 3, 4, 5, 6},
        8
}, C = {
        new int[9]{-1, 0, 3, -2, 6, 4, 1, 5, 2},
        9
};

TEST(sort, testShellSort) {
    ShellSort(A.data, A.n);
    int b[9];
    for (int i = 0; i < 8; ++i) {
        b[i + 1] = A[i];
    }
    ShellSort2(b, A.n);
    printArray(b, A.n, 1);
}

void testSort(const function<void(int a[], int n, order type)>& sort,
              Array a = C, order t = asc) {
    sort(a.data, a.n, t);
    cout << a;
}

TEST(sort, testBubbleSort) {
    testSort(BubbleSort);
}

TEST(sort, testQuickSort) {
    testSort(QuickSort);
}

TEST(sort, testSelectSort) {
    testSort(SelectSort);
}

TEST(sort, testHeap) {
    testSort(BuildHeap, A, asc);
    testSort(BuildHeap, B, desc);
    testSort(BuildHeap, C, desc);
}

TEST(sort, testHeapSort) {
    testSort(HeapSort);
    testSort(HeapSort, C, desc);
}

TEST(sort, testMergeSort) {
    testSort(MergeSort);
    testSort(MergeSort, C, desc);
}
