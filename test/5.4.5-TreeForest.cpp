//
// Created by hasee on 2021/10/13.
//

#include <gtest/gtest.h>

#include "../myLib/tree/Tree.h"

TEST(TreeForest, testTreeOrder) {
    TreeNode *R = new TreeNode(1, {
        new TreeNode(2, {
            new TreeNode(5),
            new TreeNode(6),
        }),
        new TreeNode(3, {
            new TreeNode(7)
        }),
        new TreeNode(4)
    });

    TreeNode *R2 = new TreeNode({1, 'A'}, {
        new TreeNode({2, 'B'}, {
            new TreeNode({5, 'E'}, {
                new TreeNode({11, 'K'})
            }),
            new TreeNode({6, 'F'}),
            }),
            new TreeNode({3, 'C'}, {
                new TreeNode({7, 'G'})
            }),
            new TreeNode({4, 'D'}, {
                new TreeNode({8, 'H'}),
                new TreeNode({9, 'I'}),
                new TreeNode({10, 'J'})
            })
    });
    order(R2, Pre);
}