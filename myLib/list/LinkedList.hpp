//
// Created by hasee on 2021/6/25.
//

#ifndef ALGORITHMEXERCISE_LINKEDLIST_HPP
#define ALGORITHMEXERCISE_LINKEDLIST_HPP

template<typename E>
struct LNode {
    E data;
    LNode *next;
};

template<typename E>
using LinkedList = LNode<E>*;

template<typename E>
std::ostream &operator<<(std::ostream &out, LinkedList<E> L) {

    LNode<E> *p;
    p = L->next;
    out << "Linked List:" << std::endl;
    while (p) {
        out << p->data;
        p = p->next;
    }

    return out;
}

//template<typename E>
//bool InitList(LinkedList<E> &L) {
//    L = new LinkedList<E>;
//    if (L == NULL)
//        return false;
//    L->next = NULL;
//    return true;
//}

template<typename E>
bool empty(LinkedList<E> L) {
    return L == NULL;
}

template<typename E>
LinkedList<E> List_HeadInsert(LinkedList<E> &L) {

    LNode<E> *s;
    int x;
//    L = (LinkedList<E>*)malloc(sizeof(LNode<E>));
//    L = new LinkedList<E>;
    L->next = nullptr;
    std::cin >> x;
    while (x != 9999) {
        s = new LNode<E>;
        s->data = x;
        s->next = L->next;
        L->next = s;
        std::cin >> x;
    }

    return L;
}

template<typename E>
LinkedList<E> List_TailInsert(LinkedList<E> &L, std::vector<E> values = {}) {

//    L = new LinkedList<E>;

    LNode<E> *s, *r = L;

    for (auto v : values) {
        s = new LNode<E>;
        s->data = v;
        r->next = s;
        r = s;
    }
    r->next = NULL;
    return L;
}

template<typename E>
LNode<E> *GetElem(LinkedList<E> L, int i) {

    int j = i;
    LNode<E> *p = L->next;
    if (i == 0)
        return L;
    if (i < 0)
        return NULL;

    while (p && j < i) {
        p = p->next;
        j++;
    }

    return p;
}



#endif //ALGORITHMEXERCISE_LINKEDLIST_HPP
