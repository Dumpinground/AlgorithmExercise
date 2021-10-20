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

ArcNode::ArcNode(int vex, ArcNode *next, int w) :
adjVex(vex), next(next), weight(w) {}

ALGraph::ALGraph(std::vector<char> vertex, vector<vector<int>> edges) {

    vexNum = vertex.size();

    for (int i = 0; i < vexNum; ++i) {
        vertices[i] = {vertex[i]};
    }

    arcNum = edges.size();

    for (auto e : edges) {
        basic::Edge edge(e[0], e[1]);
        append(edge.x, edge.y);
    }
}

void ALGraph::append(int x, int y) {
    ArcNode *p = vertices[x].first;
    if (!p) {
        vertices[x].first = new ArcNode(y);
        return;
    }
    while (p->next)
        p = p->next;
    p->next = new ArcNode(y);
}

bool Adjacent(const MGraph& G, int x, int y) {
    return G.Edge[x][y];
}

ArcNode *Adjacent(const ALGraph &G, int x, int y) {
    ArcNode *p = G.vertices[x].first;
    while (p) {
        if (p->adjVex == y)
            break;
        p = p->next;
    }
    return p;
}

void Neighbors(MGraph &G, int x) {
    if (G.invalid.find(x) != G.invalid.end()) {
        cout << "vertex deleted" << endl;
        return;
    }

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

void Neighbors(ALGraph &G, int x) {
    if (G.invalid.find(x) != G.invalid.end()) {
        cout << "vertex deleted" << endl;
        return;
    }
    cout << "Vertex: " << G.vertices[x].data << endl << "out:";
    auto *p = G.vertices[x].first;
    while (p) {
        cout << " <" << x << ", " << p->adjVex << ">";
        p = p->next;
    }
    cout << endl << "in:";
    p = G.vertices[x].first;
    while (p) {
        cout << " <" << p->adjVex << ", " << x << ">";
        p = p->next;
    }
    cout << endl;
}

void InsertVertex(MGraph &G, char x) {
    if (G.invalid.empty())
        G.Vex[G.vexNum++] = x;
    else {
        auto it = G.invalid.begin();
        G.Vex[*it] = x;
        G.invalid.erase(it);
    }
}

void InsertVertex(ALGraph &G, char x) {
    if (G.invalid.empty())
        G.vertices[G.vexNum++].data = x;
    else {
        auto it = G.invalid.begin();
        G.vertices[*it].data = x;
        G.invalid.erase(it);
    }
}

void DeleteVertex(MGraph &G, int x) {
    G.invalid.insert(x);
    for (int i = 0; i < G.vexNum; ++i) {
        G.Edge[x][i] = 0;
        G.Edge[i][x] = 0;
    }
}

void DeleteVertex(ALGraph &G, int x) {
    G.invalid.insert(x);
    G.vertices[x].first = NULL;
    ArcNode *p;
    for (int i = 0; i < G.vexNum; ++i) {
        RemoveEdge(G, i, x);
//        p = G.vertices[i].first;
//        while (p) {
//            if (p->adjVex == x) {
//                if (p->next)
//                    p->adjVex = p->next->adjVex;
//                p->next = p->next->next;
//            }
//            p = p->next;
//        }
    }
}

void AddEdge(MGraph &G, int x, int y) {
    G.Edge[x][y] = 1;
}

void AddEdge(ALGraph &G, int x, int y) {
    G.append(x, y);
}

void RemoveEdge(MGraph &G, int x, int y) {
    G.Edge[x][y] = 0;
}

void RemoveEdge(ALGraph &G, int x, int y) {
    ArcNode *prev = G.vertices[x].first;
    if (prev)
        if (prev->adjVex == y) {
            G.vertices[x].first = prev->next;
        } else {
            auto p = prev->next;
            while (p) {
                if (p->adjVex == y)
                    prev->next = p->next;
                else {
                    prev = p;
                    p = p->next;
                }
            }
        }
}

int FirstNeighbor(const MGraph& G, int x) {
    for (int i = 0; i < G.vexNum; ++i) {
        if (G.Edge[x][i])
            return i;
    }
    for (int i = 0; i < G.vexNum; ++i) {
        if (G.Edge[i][x])
            return i;
    }
    return -1;
}

int FirstNeighbor(const ALGraph& G, int x) {
    if (G.vertices[x].first)
        return G.vertices[x].first->adjVex;
    for (int i = 0; i < G.vexNum; ++i) {
        auto p = G.vertices[i].first;
        while (p) {
            if (p->adjVex == x)
                return i;
            p = p->next;
        }
    }
    return -1;
}

int NextNeighbor(const MGraph& G, int x, int y) {
    for (int i = y + 1; i < G.vexNum; ++i) {
        if (G.Edge[x][i])
            return i;
    }
    return -1;
}

int NextNeighbor(const ALGraph& G, int x, int y) {
    auto p = G.vertices[x].first;
    while (p && p->adjVex != y) {
        p = p->next;
    }
    if (p && p->next)
        return p->next->adjVex;
    else
        return -1;
}

int Get_Edge_Value(const MGraph& G, int x, int y) {
    return G.Edge[x][y];
}

int Get_Edge_Value(const ALGraph& G, int x, int y) {
    auto p = Adjacent(G, x, y);
    return p ? p->weight : 0;
}

void Set_Edge_Value(MGraph &G, int x, int y, int v) {
    G.Edge[x][y] = v;
}

void Set_Edge_Value(const ALGraph& G, int x, int y, int v) {
    auto p = Adjacent(G, x, y);
    if (p)
        p->weight = v;
}

