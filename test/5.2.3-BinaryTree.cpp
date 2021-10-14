//
// Created by hasee on 2021/9/30.
//

#include <gtest/gtest.h>
#include <queue>
#include <stack>

#include "../myLib/tree/binaryTree.h"
#include "../myLib/tree/ThreadTree.h"

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
    levelOrder(root);
    for (int i = 1; i <= 3; ++i) {
        order(root, static_cast<OrderType>(i));
        cout << endl;
    }
}

TEST(bt, print) {
    vector<ElemType> data;
    for (int i = 2; i <= 20; ++i) {
        data.push_back({i});
    }
    BiTree root = new BiTNode({1});
    CompleteBuild(root, data);
    root->printTree();
}

TEST(bt, thread) {
    vector<ElemType> data;
    for (int i = 2; i <= 6; ++i) {
        data.push_back({i});
    }
    ThreadTree root = new ThreadNode({1});
    CompleteBuild(root, data);
    root->lchild->lchild->append(new ThreadNode({7}), childNode::right);

    auto unlink = [](ThreadTree T) {
        if (T->ltag) {
            T->lchild = NULL;
            T->ltag = false;
        }
        if (T->rtag) {
            T->rchild = NULL;
            T->rtag = false;
        }
    };

    threadBuild(root, In);
    threadOrder(root, In);
    cout << endl;
    threadOrder(root, In, true);
    cout << endl;
    levelOrder(root, unlink);

    threadBuild(root, Pre);
    threadOrder(root, Pre);
    cout << endl;
    threadOrder(root, Pre, true);
    cout << endl;
    levelOrder(root, unlink);

    threadBuild(root, Post);
    threadOrder(root, Post);
    cout << endl;
    threadOrder(root, Post, true);
    cout << endl;
    levelOrder(root, unlink);
}

void InvertLevel(BiTree T, function<void(BiTNode *n)> visit) {
    stack<BiTNode *> S;
    levelOrder(T, [&S](BiTNode *n) {
        S.push(n);
    });
    while (!S.empty()) {
        visit(S.top());
        S.pop();
    }
}

TEST(bt, 4) {
    BiTree T =
            new BiTNode({1},
                        new BiTNode({2},
                                    new BiTNode({4}),
                                    new BiTNode({5})),
                        new BiTNode({3},
                                    new BiTNode({6}),
                                    new BiTNode({7})));
    InvertLevel(T, [](BiTNode *n) { cout << n << " "; });
}

TEST(bt, 6) {
    BiTree T =
            new BiTNode({1},
                        new BiTNode({2},
                                    new BiTNode({4}),
                                    new BiTNode({5})),
                        new BiTNode({3},
                                    new BiTNode({6}),
                                    new BiTNode({7})));

    struct treeArray {
        BiTree data[7];
        int i = 0;
    } A, B;
    order(T, Pre, [&A](BiTNode *n) {
        A.data[A.i++] = n;
    });
    order(T, In, [&B](BiTNode *n) {
        B.data[B.i++] = n;
    });
    for (auto d: A.data) {
        cout << d->data << " ";
    }
    cout << endl;
    for (auto d: B.data) {
        cout << d->data << " ";
    }
    cout << endl;
}
