//
// Created by hasee on 2021/10/3.
//

#include "TreeElement.h"

using namespace std;

std::ostream &operator<<(std::ostream &out, ElemType e) {
    out << e.toString();
    return out;
}

std::string ElemType::toString() const {
    string s = "{";
    if (value)
        s += " " + to_string(value);
    if (character)
        s += " " + to_string(character);
    s += " }";
    return s;
}

unsigned long long ElemType::length() const {
    return toString().length();
}
