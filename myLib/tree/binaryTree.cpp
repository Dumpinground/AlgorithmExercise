//
// Created by hasee on 2021/9/30.
//

#include <iostream>
#include <queue>
#include "binaryTree.h"

using namespace std;

std::ostream &operator<<(std::ostream &out, ElemType e) {
    out << e.value;
    return out;
}

std::ostream &operator<<(std::ostream &out, BiTNode *n) {
    out << "{ " << n->data << " }";
//    if (n->lchild)
//        out << "\n left: " << n->lchild;
//    if (n->rchild)
//        out << "\n right: " << n->rchild;
    return out;
}

BiTNode::BiTNode(ElemType e) {
    data = e;
    lchild = NULL;
    rchild = NULL;
}

//BiTNode::BiTNode(const std::vector<ElemType>& es) {
//    queue<BiTNode *> q;
//    for (auto &e : es) {
//        if (q.empty()) {
//            data = e;
//            q.push(this);
//        } else {
//            BiTNode *p = q.front();
//            if (!p->lchild) {
//                p->lchild->data = e;
//                q.push(p->lchild);
//            } else {
//                p->rchild->data = e;
//                q.push(p->rchild);
//                q.pop();
//            }
//        }
//    }
//}

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

void visit(BiTNode* n) {
    cout << n << " ";
}

void order(BiTree T, OrderType type) {

    if (T) {
        if (type == Pre) visit(T);
        order(T->lchild, type);
        if (type == In) visit(T);
        order(T->rchild, type);
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

void levelOrder(BiTree T) {
    queue<BiTNode *> Q;
    BiTNode *p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        cout << p << " ";
        if (p->lchild)
            Q.push(p->lchild);
        if (p->rchild)
            Q.push(p->rchild);
    }
    cout << endl;
}