//
// Created by hasee on 2021/10/14.
//

#include "binarySearchTree.h"

std::ostream &operator<<(std::ostream &out, BSTNode *p) {
    out << " " << p->key << " ";
    return out;
}

BSTNode::BSTNode(int e) :
key(e), lchild(NULL), rchild(NULL) {}

BSTNode::BSTNode(std::vector<int> es) {
    for (auto e : es) {

    }
}
