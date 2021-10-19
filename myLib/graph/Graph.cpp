//
// Created by hasee on 2021/10/17.
//

#include "Graph.h"

#include <iostream>

using namespace std;

basic::Edge::Edge(int x, int y) :
x(x), y(y), value(1) {}

MGraph::MGraph(vector<char> vertex, vector<vector<int>> edges) {
    vexNum = vertex.size();

    for (int i = 0; i < vexNum; ++i) {
        Vex[i] = vertex[i];
    }

    arcNum = edges.size();

    for (auto e : edges) {
        basic::Edge edge(e[0], e[1]);
        Edge[edge.x][edge.y] = edge.value;
    }
}

ArcNode::ArcNode(int vex, ArcNode *next) :
adjVex(vex), next(next) {}

ALGraph::ALGraph(std::vector<char> vertex, vector<vector<int>> edges) {

    vexNum = vertex.size();

    for (int i = 0; i < vexNum; ++i) {
        vertices[i] = {vertex[i], new ArcNode(i)};
    }

    arcNum = edges.size();

    for (auto e : edges) {
        basic::Edge edge(e[0], e[1]);
        append(edge.x, edge.y);
    }
}

void ALGraph::append(int x, int y) {
    ArcNode *&p = vertices[x].first;
    while (p)
        p = p->next;
    p = new ArcNode(y);
}

bool Adjacent(MGraph G, int x, int y) {
    return G.Edge[x][y];
}

bool Adjacent(ALGraph G, int x, int y) {
    ArcNode *p = G.vertices[x].first->next;
    while (p) {
        if (p->adjVex == y)
            return true;
        p = p->next;
    }
    return false;
}

void Neighbors(MGraph G, int x) {
    cout << "Vertex: " << G.Vex[x] << endl << "out:";
    for (int i = 0; i < G.vexNum; ++i) {
        if (G.Edge[x][i])
            cout << " <" << x << ", " << i << ">";
    }
    cout << endl << "in:";
    for (int i = 0; i < G.vexNum; ++i) {
        if (G.Edge[i][x])
            cout << " <" << i << ", " << x << ">";
    }
    cout << endl;
}

void Neighbors(ALGraph G, int x) {
    cout << "Vertex: " << G.vertices[x].data << endl << "out:";
    auto *p = G.vertices[x].first->next;
    while (p) {
        cout << " <" << x << ", " << p->adjVex << ">";
        p = p->next;
    }
    cout << endl << "in:";
    for (int i = 0; i < G.vexNum; ++i) {
        p = G.vertices[i].first->next;
        while (p) {
            if (p->adjVex == x)
                cout << " <" << i << ", " << x << ">";
            p = p->next;
        }
    }
    cout << endl;
}

void InsertVertex(MGraph G, char x) {
    G.Vex[G.vexNum++] = x;
}

void InsertVertex(ALGraph G, char x) {
    G.vertices[G.vexNum++].data = x;
}
