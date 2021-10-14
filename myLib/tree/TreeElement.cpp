//
// Created by hasee on 2021/10/3.
//

#include "TreeElement.h"

std::ostream &operator<<(std::ostream &out, ElemType e) {
    out << "{";
    if (e.value)
        out << " " << e.value;
    if (e.character)
        out << " " << e.character;
    out << " }";
    return out;
}
