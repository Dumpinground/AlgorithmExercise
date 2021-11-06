//
// Created by hasee on 2021/10/31.
//

#ifndef ALGORITHMEXERCISE_SORT_H
#define ALGORITHMEXERCISE_SORT_H

#include <ostream>

namespace heap {
    enum order {
        max, min
    };
}

void printArray(int a[], int n, int offset = 0);

void InsertSort(int A[], int n);
void InsertSortBinary(int A[], int n);

void ShellSort(int A[], int n);
void ShellSort2(int A[], int n);

void BubbleSort(int A[], int n);

void QuickSort(int A[], int n);

void SelectSort(int A[], int n);

void BuildHeap(int A[], int n, heap::order type);

#endif //ALGORITHMEXERCISE_SORT_H
