//
// Created by hasee on 2021/6/27.
//

#ifndef ALGORITHMEXERCISE_LINKEDLIST_H
#define ALGORITHMEXERCISE_LINKEDLIST_H

typedef int ElemType;

typedef struct LNode {
    ElemType data;
    LNode *next;
} *LinkedList;

std::ostream &operator<<(std::ostream &out, LinkedList L) {

    LNode *p;
    p = L->next;
    out << "Linked List:" << std::endl;
    out << "Head";
    while (p) {
        out << " -> " << p->data;
        p = p->next;
    }
    out << std::endl;

    return out;
}

std::ostream &operator<<(std::ostream &out, LNode &node) {
    out << "Node: " << node.data << std::endl;
    return out;
}

bool InitList(LinkedList &L) {
    L = (LinkedList)malloc(sizeof(LinkedList));
    if (L == NULL)
        return false;
    L->next = NULL;
    return true;
}

bool empty(LinkedList L) {
    return L == NULL;
}


LinkedList List_HeadInsert(LinkedList &L, std::vector<ElemType> values = {}) {

    LNode *s;
    int x;

    L->next = NULL;
    if (values.empty()) {
        std::cout << "Head Insert | End With 9999" << std::endl;
        std::cin >> x;
        while (x != 9999) {
            s = (LNode*)malloc(sizeof(LNode));
            s->data = x;
            s->next = L->next;
            L->next = s;
            std::cin >> x;
        }
    } else {
        for (auto v: values) {
            s = (LNode*)malloc(sizeof(LNode));
            s->data = v;
            s->next = L->next;
            L->next = s;
        }
    }

    return L;
}


LinkedList List_TailInsert(LinkedList &L, std::vector<ElemType> values = {}) {

    int x;
    LNode *s, *r = L;

    if (values.empty()) {
        std::cout << "Tail Insert | End With 9999" << std::endl;
        std::cin >> x;
        while (x != 9999) {
            s = (LNode*) malloc(sizeof(LNode));
            s->data = x;
            r->next = s;
            r = s;
            std::cin >> x;
        }
    } else {
        for (auto v: values) {
            s = (LNode*) malloc(sizeof(LNode));
            s->data = v;
            r->next = s;
            r = s;
        }
    }
    r->next = NULL;
    return L;
}


LNode *GetElem(LinkedList L, int i) {

    int j = 0;
    LNode *p = L;
//    if (i == 0)
//        return L;
    if (i < 0)
        return NULL;

    while (p->next && j < i) {
        p = p->next;
        j++;
    }

    return p;
}

LNode *LocateElem(LinkedList L, ElemType e) {

    LNode *p = L->next;
    while (p->data != e)
        p = p->next;

    return p;
}

bool ListInsert(LinkedList L, int i, ElemType e) {

    if (i <= 0)
        return false;

    LNode *s = (LNode*) malloc(sizeof(LNode)), *p;
    s->data = e;

    p = GetElem(L, i - 1);

    if (p->next == NULL)
        return false;

    s->next = p->next;
    p->next = s;

    return true;
}

bool ListDelete(LinkedList &L, int i, ElemType &e) {

    if (i < 1)
        return false;

    LNode *p = L;
    int j = 0;
    while (p->next && j++ < i - 1) {
        p = p->next;
    }
    if (p->next) {
        LNode *q = p->next;
        e = q->data;
        p->next = q->next;
        free(q);
        return true;
    } else {
        return false;
    }
}

bool InsertNextNode(LNode *p, ElemType e) {
    if (!p)
        return false;
    LNode *s = (LNode*) malloc(sizeof(LNode));
    if (!s)
        return false;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

bool InsertPriorNode(LNode *p, ElemType e) {
    if (!p)
        return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    if (!s)
        return false;
    s->next = p->next;
    p->next = s;
    s->data = p->data;
    p->data = e;

    return true;
}

bool DeleteNode(LNode *p) {
    if (!p)
        return false;
    LNode *q = p->next;
    if (q) {
        p->data = q->data;
        p->next = q->next;
        free(q);
    } else {
        //TODO Length Delete
    }
    return true;
}

#endif //ALGORITHMEXERCISE_LINKEDLIST_H
