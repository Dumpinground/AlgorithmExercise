//
// Created by hasee on 2021/9/4.
//

#include "TypeElement.h"

std::ostream &operator<<(std::ostream &out, LNode *N) {
    LNode *n = N;
    while (n->next) {
        n = n->next;
        out << " -> " << n->data;
    }
    out << std::endl;
    return out;
}

std::ostream &operator<<(std::ostream &out, DNode *D) {
    DNode *n = D;
    while (n->next) {
        n = n->next;
        out << " <-> " << n->data;
    }
    out << std::endl;
    return out;
}