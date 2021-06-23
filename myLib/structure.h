//
// Created by hasee on 2021/6/23.
//

#ifndef ALGORITHMEXERCISE_STRUCTURE_H
#define ALGORITHMEXERCISE_STRUCTURE_H

#include <iostream>

#include "list.h"

template<typename E>
std::ostream &operator<<(std::ostream &out, SeqList<E> &L) {
    std::string s;
    for (int i = 0; i < L.length; i++) {
        out << "a" << i + 1 << " : " << L.data[i] << std::endl;
    }
    return out;
}

#endif //ALGORITHMEXERCISE_STRUCTURE_H
