//
// Created by hasee on 2021/10/19.
//

#include <gtest/gtest.h>

#include "../myLib/graph/Graph.h"

using namespace std;

TEST(graph, testMGraph) {
    Graph g1 = {
            {'A', 'B', 'C', 'D', 'E', 'F'},
            {
                    {0, 1}, {0, 2}, {0, 3},
                    {1, 0}, {1, 4}, {1, 5},
                    {2, 0}, {2, 4},
                    {3, 0}, {3, 5},
                    {4, 1}, {4, 2},
                    {5, 1}, {5, 3}
            }
    };

    MGraph graph(g1);
    cout << Adjacent(graph, 2, 3) << " " << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 0);
    DeleteVertex(graph, 4);
    cout << Adjacent(graph, 4, 2) << endl;
    Neighbors(graph, 4);
    InsertVertex(graph, 'G');
    Neighbors(graph, 4);
}

TEST(graph, testALGraph) {
    Graph g2 = {
            {'A', 'B', 'C', 'D', 'E', 'F'},
            {
                 {0, 1},
                 {2, 0},
                 {3, 0},
                 {4, 1}, {4, 2},
                 {5, 1}, {5, 3}
            }
    };

    ALGraph graph(g2);
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
        printf("{%d, %d} ", e.x, e.y);
    }
}

TEST(graph, firstNeighbor) {
    MGraph graph(searchG1);
    cout << FirstNeighbor(graph, 2) << endl;
}

TEST(graph, testBFS) {
    MGraph graphM(searchG1);
    BFS_MinDistance(graphM, 1);
    BFS_MinDistance(graphM, 2);
}

TEST(graph, testDijkstra) {
    Graph five = {
            {'0', '1', '2', '3', '4'},
            {
                    {0, 1, 10},
                    {0, 4, 5},
                    {1, 2, 1},
                    {1, 4, 2},
                    {2, 3, 4},
                    {3, 0, 7},
                    {3, 2, 6},
                    {4, 1, 3},
                    {4, 2, 9},
                    {4, 3, 2}
            }
    };

    MGraph graph(five);
    Dijkstra(graph, '0');
}

TEST(graph, testIndex) {
    MGraph graph({
         {'0', '1', '2'},
         {
          {0, 1, 6},
          {0, 2, 13},
          {1, 0, 10},
          {1, 2, 4},
          {2, 0, 5}
         }
    });

    for (short i = 0; i < 3; ++i) {
        cout << graph.getIndex(('0' + i)) << " ";
    }
}

TEST(graph, testFloyd) {
    Graph three = {
            {'0', '1', '2'},
            {
                    {0, 1, 6},
                    {0, 2, 13},
                    {1, 0, 10},
                    {1, 2, 4},
                    {2, 0, 5}
            }
    };
    MGraph graph(three);
    Floyd(graph);
}

TEST(graph, testFloyd2) {
    Graph five = {
            {'0', '1', '2', '3', '4'},
            {
                    {0, 2, 1},
                    {0, 4, 10},
                    {1, 3, 1},
                    {1, 4, 5},
                    {2, 1, 1},
                    {2, 4, 7},
                    {3, 4, 1},
            }
    };
    MGraph graph(five);
    Floyd(graph);
}

TEST(graph, testDegree) {
    Graph five = {
            {'0', '1', '2', '3', '4'},
            {
                {0, 1},
                {1, 3},
                {2, 3},
                {2, 4},
                {3, 4}
            }
    };

    MGraph graph(five);
    for (int i = 0; i < graph.vexNum; ++i) {
        cout << graph.degree(i, basic::in) << " ";
        cout << graph.degree(i, basic::out) << endl;
    }
}

Graph AOV = {
    {'0', '1', '2', '3', '4'},
    {
            {0, 1},
            {1, 3},
            {2, 3},
            {2, 4},
            {3, 4}
    }
};

TEST(graph, testTopSort) {
    MGraph graph(AOV);
    cout << TopSort(graph, false) << endl;
    cout << TopSort(graph, true) << endl;
}

TEST(graph, testTopSortDFS) {
    MGraph graph(AOV);
    cout << TopSortDFS(graph, false) << endl;
    cout << TopSortDFS(graph, true) << endl;
}