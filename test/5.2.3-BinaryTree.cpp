//
// Created by hasee on 2021/9/30.
//

#include <gtest/gtest.h>

#include "../myLib/tree/binaryTree.h"

using namespace std;

TEST(bt, binaryTree) {

//    BiTree root = NULL;
//    root = (BiTree) malloc(sizeof(BiTNode));
    BiTree root = new BiTNode({1});

    root->data = {1};
    root->lchild = NULL;
    root->rchild = NULL;

//    BiTNode *p = new BiTNode({2});
    root->lchild = new BiTNode({2});
    root->rchild = new BiTNode({3});
    root->lchild->lchild = new BiTNode({4});

//    cout << root->data << " " << root->lchild->data << endl;
    cout << root << endl;
}

TEST(bt, order) {
    vector<ElemType> data;
    for (int i = 2; i <= 20; ++i) {
        data.push_back({i});
    }
    BiTree root = new BiTNode({1});
    CompleteBuild(root, data);
//    PreOrder(root);
    levelOrder(root);
    for (int i = 1; i <= 3; ++i) {
        order(root, static_cast<OrderType>(i));
        cout << endl;
    }
}
