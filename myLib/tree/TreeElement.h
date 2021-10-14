//
// Created by hasee on 2021/10/3.
//

#ifndef ALGORITHMEXERCISE_TREEELEMENT_H
#define ALGORITHMEXERCISE_TREEELEMENT_H

#include <ostream>

struct ElemType {

    int value;
    char character;

    friend std::ostream &operator<<(std::ostream &out, ElemType);
};

enum OrderType {
    Pre = 1,
    In = 2,
    Post = 3
};

#endif //ALGORITHMEXERCISE_TREEELEMENT_H
