//
// Created by hasee on 2021/10/2.
//

#include <gtest/gtest.h>

using namespace std;

template<typename F>
void cal(F f) {
    auto &&res = f();
}

TEST(test, func) {
    cout << (true || false && false) << endl;
    cout << sizeof(double) << endl;
}