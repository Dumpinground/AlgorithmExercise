//
// Created by hasee on 2021/9/30.
//

#ifndef ALGORITHMEXERCISE_BINARYTREE_H
#define ALGORITHMEXERCISE_BINARYTREE_H

#define MaxSize 100

#include <ostream>
#include <vector>

struct ElemType {

    int value;

    friend std::ostream &operator<<(std::ostream &out, ElemType);
};

//struct TreeNode {
//    ElemType value;
//    bool isEmpty;
//};

enum OrderType {
    Pre = 1,
    In = 2,
    Post = 3
};

struct BiTNode {
    ElemType data;
    BiTNode *lchild, *rchild;

//    enum OrderType {
//        PreOrder = 1,
//        InOrder = 2,
//        PostOrder = 3
//    };

    BiTNode(ElemType e);
//    BiTNode(const std::vector<ElemType>& es);

    friend std::ostream &operator<<(std::ostream &out, BiTNode*);
};

typedef BiTNode *BiTree;

void CompleteBuild(BiTree T, const std::vector<ElemType>& es);

void order(BiTree T, OrderType type);

void PreOrder(BiTree T);

void InOrder(BiTree T);

void PostOrder(BiTree T);

void levelOrder(BiTree T);

#endif //ALGORITHMEXERCISE_BINARYTREE_H
