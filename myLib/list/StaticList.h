//
// Created by hasee on 2021/8/7.
//

#ifndef ALGORITHMEXERCISE_STATICLIST_H
#define ALGORITHMEXERCISE_STATICLIST_H

#define MaxSize 10
#define Dirty -2
#define End -1

typedef int ElemType;

typedef struct Node {
    ElemType data;
    int next = Dirty;
} SLinkedList[MaxSize];

std::ostream &operator<<(std::ostream &out, SLinkedList L) {
    auto gap1 = std::setw(15);
    auto gap2 = std::setw(5);
    int p = L[0].next;
    out.setf(std::ostream::right);
    out << "Static List:" << std::endl;
    out << 0 << gap1 << "Head" << gap2 << p << std::endl;
    for (int i = 1; i < MaxSize; ++i) {
        out << i << gap1 << L[i].data << gap2 << L[i].next << std::endl;
    }
    return out;
}

bool InitList(SLinkedList &L) {
    L[0].next = End;
    return true;
}

int LocateNode(SLinkedList &L, int i) {
    int p = 0;
    while (p != i && p != End) {
        p = L[p].next;
    }
    return p;
}

bool ListInsert(SLinkedList &L, int i, ElemType e) {
    int p = 0;
    while (L[++p].next != Dirty);
    L[p].data = e;
    int prior = LocateNode(L, i - 1);
    if (prior < 0)
        return false;
    int n = L[prior].next;
    L[prior].next = p;
    L[p].next = n;
    return true;
}

bool ListDelete(SLinkedList &L, int i) {
    int prior = LocateNode(L, i - 1);
    if (prior < 0)
        return false;
    int p = L[prior].next;
    L[prior].next = L[p].next;
    L[p].next = Dirty;
    return true;
}

#endif //ALGORITHMEXERCISE_STATICLIST_H
