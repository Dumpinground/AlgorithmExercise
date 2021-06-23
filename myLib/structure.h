//
// Created by hasee on 2021/6/23.
//

#ifndef ALGORITHMEXERCISE_STRUCTURE_H
#define ALGORITHMEXERCISE_STRUCTURE_H

#include <iostream>

#include "list.h"

template<typename E>
std::ostream &operator<<(std::ostream &out, SeqList<E> &L) {
    out << "Array List:" << std::endl;
    out << "Index" << "\t";
    for (int i = 0; i < L.length; ++i) {
        out << i + 1 << "\t";
    }
    out << std::endl;
    out << "Value" << "\t";
    for (int i = 0; i < L.length; ++i) {
        out << L.data[i] << "\t";
    }
    out << std::endl;
    return out;
}

#endif //ALGORITHMEXERCISE_STRUCTURE_H
