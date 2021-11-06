//
// Created by hasee on 2021/10/31.
//

#include "Sort.h"
#include <iostream>

using namespace std;

void printArray(int a[], int n, int offset) {
    for (int i = 0 + offset; i < n + offset; ++i) {
        cout << " " << a[i];
    }
    cout << endl;
}

void InsertSort(int *A, int n) {

    int i, j, temp;
    for (i = 1; i < n; ++i) {
        if (A[i] < A[i - 1]) {
            temp = A[i];
            for (j = i; j > 0 && A[j - 1] > temp; --j) {
                A[j] = A[j - 1];
            }
            A[j] = temp;
        }
    }
}

void InsertSortBinary(int *A, int n) {

    int i, j, low, high, mid;
    for (i = 2; i <= n; ++i) {
        A[0] = A[i];
        low = 1, high = i - 1;
        while (low < high) {
            mid = (low + high) / 2;
            A[mid] > A[0] ? high = mid - 1 : low = mid + 1;
        }
        for (j = i; j - 1 > high; --j) {
            A[j] = A[j - 1];
        }
        A[high + 1] = A[0];
    }
}

void ShellSort(int A[], int n) {
    int d, i, j, temp;
//    A = new int[8] {6, 5, 4, 3, 2, 1, 0, -1};
    for (d = n / 2; d >= 1; d /= 2) { // 1 0 0 0 1 0 0 0    1 0 1 0 1 0 1 0
        for (int k = 0; k < d; ++k) {
            for (i = k; i < n - d; i += d) {
                if (A[i] > A[i + d]) { // 3 0 4 0 2 0 4 0

                    cout << "d " << d << ": " << A[i] << "<->" << A[i + d] << "\t";

                    temp = A[i + d];
                    for (j = i; j >= 0 && temp < A[j]; j -= d) {
                        A[j + d] = A[j];
                    }
                    A[j + d] = temp;

                    printArray(A, n);
                }
            }

        }
    }
}

void ShellSort2(int A[], int n) {
    
    int d, i, j;
    for (d = n / 2; d >= 1; d /= 2) {
        for (i = d + 1; i <= n; ++i) {
            if (A[i] < A[i - d]) {
                A[0] = A[i];
                for (j = i - d; j > 0 && A[0] < A[j]; j -= d) {
                    A[j + d] = A[j];
                }
                A[i + d] = A[0];
            }
        }
    }
}

void BubbleSort(int *A, int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = n - 1; j > i; --j) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

int Partition(int A[], int low, int high) {

    int pivot = A[low];
    auto finish = [&] ()->bool { return low == high; };
    while (!finish()) {
        while (!finish() && pivot < A[high]) high--;
        A[low] = A[high];
        while (!finish() && A[low] < pivot) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high) {

    if (low < high) {
        int pivotPos = Partition(A, low, high);
        QuickSort(A, low, pivotPos - 1);
        QuickSort(A, pivotPos + 1, high);
    }
}

void QuickSort(int *A, int n) {
    QuickSort(A, 0, n - 1);
}

void SelectSort(int *A, int n) {
    int min;
    for (int i = 0; i < n; ++i) {
        min = i;
        for (int j = i; j < n; ++j) {
            if (A[j] < A[min])
                min = j;
        }
        swap(A[i], A[min]);
    }
}

void HeadAdjust(int A[], int k, int len, heap::order type) {
    int temp = A[k];
    auto orderly = [&type] (int a, int b)->bool {
        switch (type) {
            case heap::max:
                return a >= b;
            case heap::min:
                return a <= b;
        }
    };
    for (int i = 2 * len; i < len; i *= 2) {
        if (i < len - 1 && !orderly(A[i], A[i + 1]))
            i = i + 1;
        if (orderly(temp, A[i]))
            break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = temp;
}

void BuildHeap(int *A, int len, heap::order type) {
    for (int i = len / 2; i >= 0; --i) {
        HeadAdjust(A, i, len - 1, type);
    }
}
