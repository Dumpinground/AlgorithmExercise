//
// Created by hasee on 2021/10/13.
//

#include "Tree.h"

#include <utility>

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

void order(CSNode *R, OrderType type, std::function<void(CSNode *)> visit) {
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
