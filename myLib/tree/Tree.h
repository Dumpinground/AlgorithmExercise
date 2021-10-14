//
// Created by hasee on 2021/10/5.
//

#ifndef ALGORITHMEXERCISE_TREE_H
#define ALGORITHMEXERCISE_TREE_H

#define MAX_TREE_SIZE 100

#include <functional>
#include <iostream>
#include <vector>

#include "TreeElement.h"

struct TreeNode {
    ElemType data;
    std::vector<TreeNode *> children;

    TreeNode(ElemType e);
    TreeNode(int e);
    TreeNode(ElemType e, std::vector<TreeNode *> childrenVector);
    TreeNode(int e, std::vector<TreeNode *> childrenVector);
};

struct PTNode {
    ElemType data;
    int parent;
};

struct PTree {
    PTNode nodes[MAX_TREE_SIZE];
    int n;
};

struct CTNode {
    int child;
    CTNode *next;
};

struct CTBox {
    ElemType data;
    CTNode *firstchild;
};

struct CTree {
    CTBox nodes[MAX_TREE_SIZE];
    int n, r; // n 节点数  r 根的位置
};

struct CSNode {
    ElemType data;
    CSNode *child, *sibling;
};

typedef CSNode *CSTree;

void order(TreeNode *R, OrderType type, std::function<void(TreeNode*)>
visit = [](TreeNode *r) { std::cout << r->data << " "; });

void order(CSNode *R, OrderType type, std::function<void(CSNode*)>
visit = [](CSNode *r) { std::cout << r->data << " "; });

#endif //ALGORITHMEXERCISE_TREE_H
