//
// Created by hasee on 2021/9/30.
//

#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <functional>
#include "binaryTree.h"

using namespace std;

std::ostream &operator<<(std::ostream &out, BiTNode *n) {
    out << n->data;
    return out;
}

//BiTNode::BiTNode(ElemType e)
//: data(e), lchild(NULL), rchild(NULL) {}

BiTNode::BiTNode(ElemType e, BiTNode *left, BiTNode *right) :
        data(e), lchild(left), rchild(right) {}

BiTNode::BiTNode(BiTNode *T) {
    *this = *T;
}

void BiTNode::printTree() {
    map<BiTNode *, int> numberMap;
    int n = 0;
    unsigned long long distance = 0;
    string result;
    map<BiTNode *, unsigned long long> distanceMap;
    list<BiTNode *> nodeList;

    struct Location {
        BiTNode *left, *middle, *right;
    } lo;

    auto nodeInsert = [&numberMap](list<BiTNode *> &L, BiTNode *p)->list<BiTNode *>::iterator {
        auto b = L.begin();
        if (!L.empty()) {
            for (b = L.begin(); b != L.end(); b++) {
                if (numberMap[p] < numberMap[*b]) {
                    b = L.insert(b, p);
                    return b;
                }
            }
        }
        L.push_back(p);
        b = L.end();
        return --b;
    };

    auto append = [&](BiTNode *app) {
        unsigned long long prev_length = 0;
        for (int i = 0; i < distanceMap[app]; ++i) {
            result += " ";
        }
        result += app->data.toString();
    };

    auto appendPrev = [&](BiTNode *prev, BiTNode *app) {
        unsigned long long prev_length = 0;
        if (prev)
            prev_length = distanceMap[prev] + prev->data.length();
        for (unsigned long long i = 0; i < distanceMap[app] - prev_length; ++i) {
//            cout << " ";
            result += " ";
        }
//        cout << app->data.toString();
        result += app->data.toString();
    };

    order(this, In, [&](BiTNode *p) {
        numberMap[p] = n++;
        distanceMap[p] = distance;
        distance += p->data.length();
    });
    cout << endl;

    BiTNode *prevNode;
    levelOrder(this, [&](BiTNode *p) {
        auto b = nodeInsert(nodeList, p);
        auto a = b, c = b;
        a--, c++;
        lo = {*a, *b, *c};
        if (a == nodeList.end()) {
//            cout << endl;
            result += '\n';
            prevNode = NULL;
        }
        appendPrev(prevNode, *b);
        prevNode = *b;
    });
//    cout << endl;
    cout << result << endl;
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

bool BST_Insert(BiTree &T, ElemType e) {
    if (T) {
        if (e.value < T->data.value)
            return BST_Insert(T->lchild, e);
        if (e.value > T->data.value)
            return BST_Insert(T->rchild, e);
        return false;
    }
    T = new BiTNode(e);
    return true;
}

void CreateBST(BiTree &T, std::vector<int> es) {
    for (auto &e : es) {
        BST_Insert(T, {e});
    }
}

BiTNode *BST_Search(BiTree T, int key) {

    while (T && T->data.value != key)
        if (key < T->data.value)
            T = T->lchild;
        else
            T = T->rchild;
    return T;

//    if (T) {
//        if (key < T->data.value)
//            return BST_Search(T->lchild, key);
//        if (key > T->data.value)
//            return BST_Search(T->rchild, key);
//    }
//    return T;
}

//TODO need fix
bool BST_Delete(BiTree &T, int key) {
    BiTNode *p = BST_Search(T, key);

    auto replace = [&p](BiTNode *child) {
        BiTNode *re;
        order(child, In, [&re](BiTNode *n) {
            if (!re)
                re = n;
        });
        p->data = re->data;
        BST_Delete(re, re->data.value);
    };

    if (!p)
        return false;
    if (p->lchild) {
        replace(p->lchild);
        return true;
    } else if (p->rchild) {
        replace(p->rchild);
        return true;
    }
    p = NULL;
    return true;
}
