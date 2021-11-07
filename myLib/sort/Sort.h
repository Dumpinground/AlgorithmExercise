//
// Created by hasee on 2021/10/31.
//

#ifndef ALGORITHMEXERCISE_SORT_H
#define ALGORITHMEXERCISE_SORT_H

#include <ostream>

enum order {
    asc, desc
};

bool orderly(int a, int b, order type = asc);

void printArray(int a[], int n, int offset = 0);

void InsertSort(int A[], int n);
void InsertSortBinary(int A[], int n);

void ShellSort(int A[], int n);
void ShellSort2(int A[], int n);

void BubbleSort(int A[], int n, order type = asc);

void QuickSort(int A[], int n, order type = asc);

void SelectSort(int A[], int n, order type = asc);

void BuildHeap(int A[], int n, order type = asc);

void HeapSort(int A[], int n, order type = asc);

void MergeSort(int A[], int n, order type = asc);

#endif //ALGORITHMEXERCISE_SORT_H
