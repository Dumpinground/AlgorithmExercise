//
// Created by hasee on 2021/10/19.
//

#include <gtest/gtest.h>
#include <vector>

#include "../myLib/graph/Graph.h"

using namespace std;

vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {0, 3},
        {1, 0}, {1, 4}, {1, 5},
        {2, 0}, {2, 4},
        {3, 0}, {3, 5},
        {4, 1}, {4, 2},
        {5, 1}, {5, 3}
};

vector<vector<int>> arrows = {
        {0, 1},
        {2, 0},
        {3, 0},
        {4, 1}, {4, 2},
        {5, 1}, {5, 3}
};

TEST(graph, testMGraph) {
    MGraph graph({'A', 'B', 'C', 'D', 'E', 'F'}, arrows);
    cout << Adjacent(graph, 2, 3) << " " << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 0);
    InsertVertex(graph, 'G');
}

TEST(graph, testALGraph) {
    ALGraph graph({'A', 'B', 'C', 'D', 'E', 'F'}, arrows);
    cout << Adjacent(graph, 2, 3) << " " << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 0);
    InsertVertex(graph, 'G');
}