//
// Created by hasee on 2021/10/3.
//

#include <iostream>
#include <queue>
#include <map>
#include <functional>
#include <iomanip>
#include "ThreadTree.h"

using namespace std;

ThreadNode::ThreadNode(ElemType e)
        : data(e), lchild(NULL), rchild(NULL), ltag(false), rtag(false) {}

void ThreadNode::printTree() {
    map<ThreadNode *, int> treeMap;
    int n = 0;
    order(this, In, [&](ThreadTree T) {
        treeMap[T] = n++;
    });

    cout << endl;
    levelOrder(this, [&](ThreadTree T) {
        for (int i = 0; i < treeMap[T]; ++i) {
            cout << setw(14) << "";
        }
        if (T->ltag && T->lchild)
            cout << T->lchild << "<-";
        cout << T;
        if (T->rtag && T->rchild)
            cout << "->" << T->rchild;
        cout << endl;
    });

    cout << endl;
}

std::ostream &operator<<(std::ostream &out, ThreadNode *n) {
    out << n->data;
    return out;
}

void CompleteBuild(ThreadTree T, const std::vector<ElemType> &es) {
    queue<ThreadTree> q;
    q.push(T);
    for (auto &e : es) {
        ThreadNode *p = q.front(), *child = new ThreadNode(e);
        if (!p->lchild) {
            p->lchild = child;
        } else {
            p->rchild = child;
            q.pop();
        }
        q.push(child);
    }
}

void threadBuild(ThreadTree T, OrderType type) {
    ThreadNode *pre = NULL;
    order(T, type, [&](ThreadTree q) {
        if (!q->lchild) {
            q->lchild = pre;
            q->ltag = true;
        }
        if (pre && !pre->rchild) {
            pre->rchild = q;
            pre->rtag = true;
        }
        pre = q;
    });
}

void order(ThreadTree T, OrderType type, const function<void(ThreadTree)> &visit) {
    if (T) {
        if (type == Pre) visit(T);
        if (!T->ltag) order(T->lchild, type, visit);
        if (type == In) visit(T);
        if (!T->rtag) order(T->rchild, type, visit);
        if (type == Post) visit(T);
    }
}

void levelOrder(ThreadTree T, const function<void(ThreadTree)> &visit) {
    queue<ThreadNode *> Q;
    ThreadNode *p;
    Q.push(T);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        if (!p->ltag && p->lchild)
            Q.push(p->lchild);
        if (!p->rtag && p->rchild)
            Q.push(p->rchild);
    }
    cout << endl;
}

ThreadNode* FirstNode(ThreadNode *p) {
    while (!p->ltag && p->lchild)
        p = p->lchild;
    return p;
}
ThreadNode* NextNode(ThreadNode *p) {
    if (p->rtag)
        return p->rchild;
    else
        return FirstNode(p->rchild);
}
ThreadNode* LastNode(ThreadNode *p) {
    while (!p->rtag && p->rchild)
        p = p->rchild;
    return p;
}
ThreadNode* PreNode(ThreadNode *p) {
    if (p->rtag)
        return p->rchild;
    else
        return LastNode(p->rchild);
}

void threadOrder(ThreadTree T, OrderType type, bool reverse, const function<void(ThreadTree)>& visit) {

//    function<ThreadNode *(ThreadNode *)> FirstNode, NextNode, LastNode, PreNode;
//
//    FirstNode = [] (ThreadNode *p)->ThreadNode* {
//        while (!p->ltag && p->lchild)
//            p = p->lchild;
//        return p;
//    };
//    NextNode = [&FirstNode] (ThreadNode *p)->ThreadNode* {
//        if (p->rtag)
//            return p->rchild;
//        else
//            return FirstNode(p->rchild);
//    };
//    LastNode = [] (ThreadNode *p)->ThreadNode* {
//        while (!p->rtag && p->rchild)
//            p = p->rchild;
//        return p;
//    };
//    PreNode = [&LastNode] (ThreadNode *p)->ThreadNode* {
//        if (p->rtag)
//            return p->rchild;
//        else
//            return LastNode(p->rchild);
//    };

    switch (type) {
        case In:
            break;
        case Pre:
            break;
        case Post:
            break;
    }

    if (reverse)
        for (auto p = LastNode(T); p; p = PreNode(p)) {
            visit(p);
        }
    else
        for (auto p = FirstNode(T); p; p = NextNode(p)) {
            visit(p);
        }
}