//
// Created by hasee on 2021/10/31.
//

#include "Sort.h"
#include <iostream>
#include <functional>
#include <valarray>
#include <queue>

using namespace std;

bool orderly(int a, int b, order type) {
    switch (type) {
        case desc:
            return a >= b;
        case asc:
            return a <= b;
    }
    return true;
}

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

void BubbleSort(int *A, int n, order type) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (int j = n - 1; j > i; --j) {
            if (!orderly(A[j - 1], A[j], type)) {
                swap(A[j], A[j - 1]);
                swapped = true;
            }
        }
        if (!swapped)
            return;
    }
}

int Partition(int A[], int low, int high, order type) {

    int pivot = A[low];
    auto finish = [&] ()->bool { return low == high; };
    while (!finish()) {
        while (!finish() && orderly(pivot, A[high], type)) high--;
        A[low] = A[high];
        while (!finish() && orderly(A[low], pivot, type)) low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void QuickSort(int A[], int low, int high, order type) {

    if (low < high) {
        int pivotPos = Partition(A, low, high, type);
        QuickSort(A, low, pivotPos - 1, type);
        QuickSort(A, pivotPos + 1, high, type);
    }
}

void QuickSort(int *A, int n, order type) {
    QuickSort(A, 0, n - 1, type);
}

void SelectSort(int *A, int n, order type) {
    int min;
    for (int i = 0; i < n; ++i) {
        min = i;
        for (int j = i; j < n; ++j) {
            if (!orderly(A[min], A[j], type))
                min = j;
        }
        swap(A[i], A[min]);
    }
}

void HeapAdjust(int A[], int k, int len, order type) {
    int temp = A[k];

    for (int i = 2 * k + 1; i < len; i *= 2) {
        if (i < len - 1 && !orderly(A[i], A[i + 1], type))
            i = i + 1;
        if (orderly(temp, A[i], type))
            break;
        else {
            A[k] = A[i];
            k = i;
        }
    }
    A[k] = temp;
}

void BuildHeap(int *A, int len, order type) {
    for (int i = len / 2; i >= 0; --i) {
        HeapAdjust(A, i, len, type);
    }
}

void HeapSort(int *A, int n, order type) {
    type = type == asc ? desc : asc;
    BuildHeap(A, n, type);
    for (int i = n - 1; i >= 0; --i) {
        swap(A[0], A[i]);
        HeapAdjust(A, 0, i, type);
    }
}

void MergeSort(int A[], int low, int high, const function<void(int A[], int low, int mid, int high)> &Merge) {

    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(A, low, mid, Merge);
        MergeSort(A, mid + 1, high, Merge);
        Merge(A, low, mid, high);
    }
}

void MergeSort(int *A, int n, order type) {

    int B[n];
    function<void(int A[], int low, int mid, int high)> Merge;

    Merge = [&B, &type] (int A[], int low, int mid, int high) {
        int i, j, k;
        for (k = low; k <= high; k++) {
            B[k] = A[k];
        }
        for (i = low, j = mid + 1, k = i; i <= mid && j <= high; k++) {
            if (orderly(B[i], B[j], type))
                A[k] = B[i++];
            else
                A[k] = B[j++];
        }
        while (i <= mid)
            A[k++] = B[i++];
        while (j <= high)
            A[k++] = B[j++];
    };

    MergeSort(A, 0, n - 1, Merge);
}

int bitLimit(const int numbers[], int n) {
    int b = 1;
    for (int i = 0; i < n; i++) {
        while (numbers[i] / (int)pow(10, b))
            b++;
    }
    return b;
}

int bitLimit(const LinkedList &L) {
    int b = 1;
    LNode *p = L->next;
    while (p) {
        while (p->data / (int)pow(10, b))
            b++;
        p = p->next;
    }
    return b;
}

int radix(int number, int n) {
    number %= (int)pow(10.0, n);
    number /= (int)pow(10.0, n - 1);
    return number;
}

/**
 * Least Significant Digital
 */
void LSD(LinkedList &L, order type) {

    bool finish = true;
    LNode *p;
    int n = bitLimit(L);
    for (int i = 1; i <= n; ++i) {
        p = L->next;
        queue<LinkedList> bitQueue[10];
        while (p) {
            int pos = radix(p->data, i);
            bitQueue[pos].push(p);
            p = p->next;
        }
        p = L;
        for (int j = 0; j <= 9; ++j) {
            int k = type == asc ? j : 9 - j;
            while (!bitQueue[k].empty()) {
                p->next = bitQueue[k].front();
                bitQueue[k].pop();
                p = p->next;
            }
        }
        p->next = NULL;
    }

}
