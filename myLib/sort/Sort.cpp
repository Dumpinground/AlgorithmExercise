//
// Created by hasee on 2021/10/31.
//

#include "Sort.h"
#include <iostream>

using namespace std;

void printArray(int a[], int n) {
    for (int i = 0; i < n; ++i) {
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
