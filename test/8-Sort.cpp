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

void testResult(Array a, const function<void(int a[], int n)>& sort) {
    sort(a.data, a.n);
    cout << a;
}

TEST(sort, testBubbleSort) {
    testResult(A, BubbleSort);
}

TEST(sort, testQuickSort) {
    testResult(A, QuickSort);
}

TEST(sort, testSelectSort) {
    testResult(A, SelectSort);
}

TEST(sort, testHeadSort) {
    auto BuildMaxHeap = [] (int A[], int n) {
        BuildHeap(A, n, heap::max);
    };
    auto BuildMinHeap = [] (int A[], int n) {
        BuildHeap(A, n, heap::min);
    };
    testResult(B, BuildMaxHeap);
    testResult(A, BuildMinHeap);
}
