//
// Created by hasee on 2021/10/23.
//

#include "Search.h"

ElemType &SSTable::operator[](int i) {
    return elem[i];
}

const ElemType &SSTable::operator[](int i) const {
    return elem[i];
}

int Search_Seq(SSTable ST, ElemType key) {
    int i;
    for (i = 0; i < ST.TableLen && ST[i] != key; ++i);
    return i == ST.TableLen ? NotFound : i;
}

int Binary_Search(SSTable L, ElemType key) {
    int low = 0, high = L.TableLen - 1, mid;
    while (low <= high) {
        mid = ( low + high ) / 2;
        if (L[mid] == key)
            return mid;
        else
            L[mid] > key ? high = mid - 1 : low = mid + 1;
    }
    return NotFound;
}
