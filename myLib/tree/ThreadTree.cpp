//
// Created by hasee on 2021/10/3.
//

#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <functional>
#include <iomanip>

#include "ThreadTree.h"

using namespace std;

ThreadNode::ThreadNode(ElemType e):
data(e), lchild(NULL), rchild(NULL), parent(NULL), ltag(false), rtag(false) {}

int ThreadNode::depth(int d) {
    ThreadNode *p = this;
    while (p->parent) {
        d++;
        p = p->parent;
    }
    return d;
}

void ThreadNode::printTree() {
    map<ThreadNode *, int> location;
    int n = 1;
    order(this, In, [&](ThreadTree T) {
        location[T] = n++;
    });

    cout << endl;
    int d = this->depth();
    stack<ThreadTree> family;
    ThreadTree pre;
    int space;
    levelOrder(this, [&](ThreadTree p) {
        if (d != p->depth()) {
            d++;
            cout << endl;
            stack<ThreadTree>().swap(family);
            pre = NULL;
        }
        space = (location[p] - location[pre]) * 5;
        if (family.empty()) {
            family.push(p);
            cout << setw(space) << setfill(' ') << p;
        } else {
            cout << setw(space) << setfill('-') << p;
            family.pop();
        }
        pre = p;
    });

    cout << endl;
}

std::ostream &operator<<(std::ostream &out, ThreadNode *n) {
    out << n->data;
    return out;
}

void ThreadNode::showLink() {
    if (ltag && lchild)
        cout << lchild << "<-";
    cout << this;
    if (rtag && rchild)
        cout << "->" << rchild;
    cout << endl;
}

void ThreadNode::append(ThreadNode *p, childNode child) {
    switch (child) {
        case childNode::left:
            lchild = p;
            break;
        case childNode::right:
            rchild = p;
    }
    p->parent = this;
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
        child->parent = p;
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
    pre->rtag = true;
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

void threadOrder(ThreadTree T, OrderType type, bool reverse, const function<void(ThreadTree)>& visit) {

    function<ThreadNode *(ThreadNode *)> FirstNode, NextNode, LastNode, PreNode;

    switch (type) {
        case In:
            FirstNode = [] (ThreadNode *p)->ThreadNode* {
                while (!p->ltag && p->lchild)
                    p = p->lchild;
                return p;
            };
            NextNode = [&FirstNode] (ThreadNode *p)->ThreadNode* {
                if (p->rtag)
                    return p->rchild;
                else
                    return FirstNode(p->rchild);
            };
            LastNode = [] (ThreadNode *p)->ThreadNode* {
                while (!p->rtag)
                    p = p->rchild;
                return p;
            };
            PreNode = [&LastNode] (ThreadNode *p)->ThreadNode* {
                if (p->ltag)
                    return p->lchild;
                else
                    return LastNode(p->lchild);
            };

            break;

        case Pre:
            FirstNode = [] (ThreadNode *p)->ThreadNode* {
                return p;
            };

            NextNode = [] (ThreadNode *p)->ThreadNode* {
                if (!p->ltag)
                    return p->lchild;
                return p->rchild;
            };

            LastNode = [] (ThreadNode *p)->ThreadNode* {
                while (!p->rtag || !p->ltag)
                    p = p->rtag ? p->lchild : p->rchild;
                return p;
            };

            PreNode = [&LastNode] (ThreadNode *p)->ThreadNode* {
                ThreadTree pa = p->parent;
                if (pa && !pa->ltag && pa->lchild != p) {
                    return LastNode(pa->lchild);
                }
                return pa;
            };

            break;

        case Post:

            break;
    }

    if (!reverse)
        for (auto p = FirstNode(T); p; p = NextNode(p)) {
            visit(p);
        }
    else
        for (auto p = LastNode(T); p; p = PreNode(p)) {
            visit(p);
        }

}