//
// Created by hasee on 2021/6/23.
//

#ifndef ALGORITHMEXERCISE_ARRAYLIST_H
#define ALGORITHMEXERCISE_ARRAYLIST_H

#define InitSize 100
#define SizeLimit 200

template<typename E>
struct SeqList {
    E *data;
    int MaxSize, length;

    SeqList() {
        InitList(*this);
    }
};

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

template<typename E>
void InitList(SeqList<E> &L) {
    L.length = 0;
    L.data = new int[InitSize];
    L.MaxSize = SizeLimit;
}

template<typename E>
int Length(SeqList<E> &L) {
    return L.length;
}

template<typename E>
bool Empty(SeqList<E> &L) {
    return !Length(L);
}

template<typename E>
int LocateElem(SeqList<E> &L, E e) {
    for (int i = 0; i < L.length; ++i) {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}

template<typename E>
E GetElem(SeqList<E> &L, int i) {
    int I = i--;
    return L.data[i];
}

template<typename E>
bool ListInsert(SeqList<E> &L, int i, E e) {

    if (i < 1 || i > L.length + 1)
        return false;

    if (L.length >= L.MaxSize)
        return false;

    for (int j = L.length; j >= i; --j) {
        L.data[j] = L.data[j - 1];
    }

    L.data[i - 1] = e;
    L.length++;

    return true;
}

template<typename E>
bool ListDelete(SeqList<E> &L, int i, E &e) {
    if (i < 1 || i > L.length + 1)
        return false;

    e = L.data[i - 1];
    L.length--;
    for (int j = i - 1; j < L.length; ++j) {
        L.data[j] = L.data[j + 1];
    }
    return true;
}

template<typename E>
void PrintList(SeqList<E> &L) {
    for (int i = 0; i < L.length; ++i) {
        std::cout << L.data[i] << " ";
    }
    printf("\n");
}

#endif //ALGORITHMEXERCISE_ARRAYLIST_H
