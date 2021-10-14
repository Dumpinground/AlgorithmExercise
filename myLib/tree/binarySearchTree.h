//
// Created by hasee on 2021/10/14.
//

#ifndef ALGORITHMEXERCISE_BINARYSEARCHTREE_H
#define ALGORITHMEXERCISE_BINARYSEARCHTREE_H

#include <iostream>
#include <vector>

struct BSTNode {
    int key;
    BSTNode *lchild, *rchild;

    BSTNode(int e);
    BSTNode(std::vector<int>);

    friend std::ostream &operator<<(std::ostream&, BSTNode*);
};

typedef BSTNode *BSTree;

#endif //ALGORITHMEXERCISE_BINARYSEARCHTREE_H
