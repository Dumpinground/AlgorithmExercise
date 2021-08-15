//
// Created by hasee on 2021/6/23.
//

#include <gtest/gtest.h>
#include <random>

#include "../myLib/list/ArrayList.h"

using namespace std;

TEST(ArrayList, 0) {
    cout << "2.2.3 Array List" << endl << endl;
}

template<typename E>
void del_x_2(SeqList<E> &L, E x) {
    int k = 0;
    for (int i = 0; i < L.length - 1; ++i) {
        L.data[i - k] = L.data[i];
        if (L.data[i] == x)
            k++;
    }
    L.length -= k;
}

TEST(ArrayList, 3) {
    std::mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution dist(1, 5);

    SeqList<int> list;
    for (int i = 0; i < 20; ++i) {
        ListInsert(list, i + 1, dist(rng));
    }
    cout << list << endl;
    del_x_2(list, 4);
    cout << list << endl;
}

template<typename E>
bool del_s_t(SeqList<E> &L, E s, E t) {
    if (s >= t || L.length == 0) {
        return false;
    }

    int s_pos, t_pos;

    for (s_pos = 0; s_pos < L.length && L.data[s_pos] < s; ++s_pos);
    if (s_pos >= L.length)
        return false;

    for (t_pos = 0; t_pos < L.length && L.data[t_pos] <= t; ++t_pos);

    while (t_pos < L.length) {
        L.data[s_pos++] = L.data[t_pos++];
    }

    L.length = s_pos;

    return true;
}

TEST(ArrayList, 4) {
    SeqList<int> list;
    for (int i = 1; i <= 20; ++i) {
        ListInsert(list, i, i);
    }
    del_s_t(list, 3, 17);
    cout << list << endl;
}

template<typename E>
bool del_s_t2(SeqList<E> &L, E s, E t) {

    if (s >= t || L.length == 0)
        return false;

    for (int i = 0; i < L.length; ++i) {

    }

    return true;
}

TEST(ArrayList, 5) {
    std::mt19937 rng;
    rng.seed(random_device()());
    uniform_int_distribution dist(1, 5);

    SeqList<int> list;
    for (int i = 0; i < 20; ++i) {
        ListInsert(list, i + 1, dist(rng));
    }
    cout << list << endl;

    cout << list << endl;
}

