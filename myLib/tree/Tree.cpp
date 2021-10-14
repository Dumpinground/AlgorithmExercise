//
// Created by hasee on 2021/10/13.
//

#include "Tree.h"

#include <queue>

using namespace std;


using namespace std;

TreeNode::TreeNode(ElemType e) :
        data(e) {}

TreeNode::TreeNode(int e) :
        data({e}) {}

TreeNode::TreeNode(ElemType e, std::vector<TreeNode *> childrenVector)
        : data(e), children(std::move(childrenVector)) {}

TreeNode::TreeNode(int e, std::vector<TreeNode *> childrenVector)
        : data({e}), children(std::move(childrenVector)) {}

void order(TreeNode *R, OrderType type, std::function<void(TreeNode *)> visit) {
    if (R)
        switch (type) {
            case Pre:
                visit(R);
                for (auto child : R->children) {
                    order(child, Pre, visit);
                }
                break;
            case Post:
                for (auto child : R->children) {
                    order(child, Post, visit);
                }
                visit(R);
                break;
            default:
                cout << "no method" << endl;
        }
}

void levelOrder(TreeNode *R, function<void(TreeNode*)> visit) {
    queue<TreeNode *> Q;
    TreeNode *p;
    Q.push(R);
    while (!Q.empty()) {
        p = Q.front();
        Q.pop();
        visit(p);
        for (auto child : p->children) {
            if (child) Q.push(child);
        }
    }
}

void order(CSNode *R, OrderType type, function<void(CSNode *)> visit) {
    if (R)
        switch (type) {
            case Pre:
                visit(R);
                order(R->child, Pre, visit);
                break;
            case Post:
                order(R->child, Post, visit);
                visit(R);
                break;
            default:
                cout << "no method" << endl;
        }
}
