//
// Created by hasee on 2021/10/23.
//

#ifndef ALGORITHMEXERCISE_SEARCH_H
#define ALGORITHMEXERCISE_SEARCH_H

#include "../TypeElement.h"

#define NotFound -1

struct SSTable {
    ElemType *elem;
    int TableLen;

    ElemType &operator[](int i);

    const ElemType &operator[](int i) const;
};

int Search_Seq(SSTable ST, ElemType key);

int Binary_Search(SSTable L, ElemType key);

struct Node5 {
    ElemType keys[4];
    Node5 *child[5];
    int num;
};


#endif //ALGORITHMEXERCISE_SEARCH_H
