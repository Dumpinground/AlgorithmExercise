//
// Created by hasee on 2021/10/31.
//

#include "../myLib/sort/Sort.h"

#include <gtest/gtest.h>
#include <iostream>

using namespace std;

TEST(sort, 0) {
    int n = 8;
    int a[] = {6, 5, 4, 3, 2, 1, 0, -1};
    ShellSort(a, 8);
    printArray(a, n);
}
