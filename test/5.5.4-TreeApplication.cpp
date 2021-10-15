//
// Created by hasee on 2021/10/14.
//

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

#include "../myLib/tree/binaryTree.h"

using namespace std;

TEST(ta, testInsert) {
    BiTree T = new BiTNode({19});
    CreateBST(T, {19, 13, 50, 11, 26, 66, 21, 30, 60, 70});
    levelOrder(T);
    BST_Delete(T, 30);
    levelOrder(T);
}