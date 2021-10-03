//
// Created by hasee on 2021/9/30.
//

#ifndef ALGORITHMEXERCISE_BINARYTREE_H
#define ALGORITHMEXERCISE_BINARYTREE_H

#define MaxSize 100

#include <ostream>
#include <vector>

#include "TreeElement.h"

struct BiTNode {
    ElemType data;
    BiTNode *lchild, *rchild;

    BiTNode(ElemType e);
    BiTNode(BiTNode* T);

    friend std::ostream &operator<<(std::ostream &out, BiTNode *);

    void printTree();
};

typedef BiTNode *BiTree;

void CompleteBuild(BiTree T, const std::vector<ElemType> &es);

void order(BiTree T, OrderType type, const std::function<void(BiTree)>&
visit = [](BiTree T) { std::cout << T << " "; });

void PreOrder(BiTree T);

void InOrder(BiTree T);

void PostOrder(BiTree T);

void levelOrder(BiTree T, const std::function<void(BiTree)>&
visit = [](BiTree T) { std::cout << T << " "; });

#endif //ALGORITHMEXERCISE_BINARYTREE_H
