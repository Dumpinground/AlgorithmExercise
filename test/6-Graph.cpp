//
// Created by hasee on 2021/10/19.
//

#include <gtest/gtest.h>

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
    DeleteVertex(graph, 4);
    cout << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 4);
    InsertVertex(graph, 'G');
    Neighbors(graph, 4);
}

TEST(graph, testALGraph) {
    ALGraph graph({'A', 'B', 'C', 'D', 'E', 'F'}, arrows);
    cout << Adjacent(graph, 2, 3) << " " << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 4);
    DeleteVertex(graph, 4);
    cout << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 4);
    InsertVertex(graph, 'G');
    Neighbors(graph, 4);
}

Graph searchG1 = {
        {'0', '1', '2', '3', '4', '5', '6', '7', '8'},
        {
                {1, 2}, {1, 5},
                {2, 6},
                {6, 3}, {6, 7},
                {3, 4}, {3, 7},
                {4, 7}, {4, 8},
                {7, 8}
        },
        false,
        0
};

TEST(graph, graphInit) {
    for (auto e : searchG1.edges()) {
        printf("{%d, %d} ", e[0], e[1]);
    }
}

TEST(graph, firstNeighbor) {
    MGraph graph(searchG1);
    cout << FirstNeighbor(graph, 2) << endl;
}

TEST(graph, testBFS) {
    MGraph graph(searchG1);
    bool visited[graph.vexNum];
    BFS(graph, 1, visited);
    cout << endl;
    bool visited2[graph.vexNum];
    BFS(graph, 2, visited2);
}

TEST(graph, testSearch) {
    MGraph graphM(searchG1);
    BFS_MinDistance(graphM, 1);
    BFS_MinDistance(graphM, 2);
}