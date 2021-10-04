//
// Created by hasee on 2021/10/3.
//

#ifndef ALGORITHMEXERCISE_THREADTREE_H
#define ALGORITHMEXERCISE_THREADTREE_H

#include "TreeElement.h"

enum childNode {
    left = 1,
    right = 2
};

struct ThreadNode {

    ElemType data;
    ThreadNode *lchild, *rchild, *parent;
    bool ltag, rtag;

    ThreadNode(ElemType e);

    int depth(int d = 0);

    void append(ThreadNode *p, childNode);

    friend std::ostream &operator<<(std::ostream &out, ThreadNode *);

    void showLink();

    void printTree();
};

typedef ThreadNode *ThreadTree;

void CompleteBuild(ThreadTree T, const std::vector<ElemType> &es);

void threadBuild(ThreadTree T, OrderType type);

std::ostream &operator<<(std::ostream &out, ThreadNode *n);

void order(ThreadTree T, OrderType type, const std::function<void(ThreadTree)> &
visit = [](ThreadTree T) { std::cout << T << " "; });

void levelOrder(ThreadTree T, const std::function<void(ThreadTree)> &
visit = [](ThreadTree T) { std::cout << T << " "; });

void threadOrder(ThreadTree T, OrderType type, bool reverse = false, const std::function<void(ThreadTree T)>&
visit = [](ThreadTree T) { std::cout << T << " "; });

#endif //ALGORITHMEXERCISE_THREADTREE_H
