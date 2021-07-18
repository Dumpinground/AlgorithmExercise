//
// Created by hasee on 2021/7/18.
//

#ifndef ALGORITHMEXERCISE_DLINKEDLIST_H
#define ALGORITHMEXERCISE_DLINKEDLIST_H

typedef int ElemType;

typedef struct DNode{
    ElemType data;
    struct DNode *prior, *next;
} *DLinkedList;

bool InitDLinkedList(DLinkedList &L) {
    L = (DNode *) malloc(sizeof(DNode));
    if (L == NULL)
        return false;
    L->prior = NULL;
    L->next = NULL;
    return true;
}

std::ostream &operator<<(std::ostream &out, DLinkedList L) {

    DNode *p;
    p = L->next;
    out << "DLinked List:" << std::endl;
    out << "Head";
    while (p) {
        out << " <-> " << p->data;
        p = p->next;
    }
    out << " <-> NULL" << std::endl;

    return out;
}

std::ostream &operator<<(std::ostream &out, DNode &node) {
    out << "DNode: " << node.data << std::endl;
    return out;
}


bool empty(DLinkedList &L) {
    return L->next == NULL;
}

bool InsertNextDNode(DNode *p, DNode *s) {

    if (p == NULL || s == NULL)
        return false;

    s->next = p->next;
    if (p->next != NULL)
        p->next->prior = s;

    s->prior = p;
    p->next = s;

    return true;
}

bool DeleteNextDNode(DNode *p) {

    if (p==NULL)
        return false;

    DNode *q = p->next;

    if (q==NULL)
        return false;

    p->next = q->next;
    if (q->next != NULL)
        q->next->prior = p;
    free(q);

    return true;
}

void DestroyList(DLinkedList &L) {

    while (L->next) {
        DeleteNextDNode(L);
    }
    free(L);
    L=NULL;
}

#endif //ALGORITHMEXERCISE_DLINKEDLIST_H
