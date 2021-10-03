//
// Created by hasee on 2021/9/30.
//

#include <iostream>
#include <queue>
#include <map>
#include <functional>
#include "binaryTree.h"

using namespace std;

std::ostream &operator<<(std::ostream &out, BiTNode *n) {
    out << n->data;
    return out;
}

BiTNode::BiTNode(ElemType e)
: data(e), lchild(NULL), rchild(NULL) {}

BiTNode::BiTNode(BiTNode *T) {
    *this = *T;
}

void BiTNode::printTree() {
    map<BiTNode *, int> treeMap;
    int n = 0;
    order(this, In, [&](BiTree T) {
        treeMap[T] = n++;
    });
    levelOrder(this, [&](BiTree T) {
        for (int i = 0; i < treeMap[T]; ++i) {
            cout << "\t";
        }
        cout << T << endl;
    });
}

void CompleteBuild(BiTree T, const std::vector<ElemType>& es) {
    queue<BiTNode *> q;
    q.push(T);
    for (auto &e : es) {
        BiTNode *p = q.front(), *child = new BiTNode(e);
        if (!p->lchild) {
            p->lchild = child;
        } else {
            p->rchild = child;
            q.pop();
        }
        q.push(child);
    }
}

void order(BiTree T, OrderType type, const function<void(BiTree)>& visit) {

    if (T) {
        if (type == Pre) visit(T);
        order(T->lchild, type, visit);
        if (type == In) visit(T);
        order(T->rchild, type, visit);
        if (type == Post) visit(T);
    }
}

void PreOrder(BiTree T) {

    if (T) {
        cout << T << " ";
        PreOrder(T->lchild);
        PreOrder(T->rchild);
    }
}

void InOrder(BiTree T) {

    if (T) {
        InOrder(T->lchild);
        cout << T << " ";
        InOrder(T->rchild);
    }
}

void PostOrder(BiTree T) {

    if (T) {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        cout << T << " ";
    }
}

void levelOrder(BiTree T, const function<void(BiTree)>& visit) {
    queue<BiTNode *> Q;
    BiTNode *p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
    cout << endl;
}
