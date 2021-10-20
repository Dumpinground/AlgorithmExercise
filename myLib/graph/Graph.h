//
// Created by hasee on 2021/10/17.
//

#ifndef ALGORITHMEXERCISE_GRAPH_H
#define ALGORITHMEXERCISE_GRAPH_H

#include <climits>
#include <vector>
#include <set>

#define MaxVertexNum 100
#define INFINITY INT_MAX

namespace basic {
    struct Edge {
        int x;
        int y;
        int value;

        Edge(int x, int y);
    };
}

struct Graph;
struct Vertex;

struct MGraph {
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum;
    std::set<int> invalid;

    MGraph() = default;
    MGraph(std::vector<char> vertex, std::vector<std::vector<int>> edges);
};

typedef char VertexType;

struct ArcNode {
    int adjVex;
    ArcNode *next;
    int weight = 0;

    ArcNode(int vex, ArcNode *next = NULL, int w = 1);
};

struct VNode {
    VertexType data;
    ArcNode *first;
};

typedef VNode AdjList[MaxVertexNum];

struct ALGraph {
    AdjList vertices;
    int vexNum, arcNum;
    std::set<int> invalid;

    ALGraph() = default;
    ALGraph(std::vector<char> vertex, std::vector<std::vector<int>> edges);

    void append(int x, int y);
};

bool Adjacent(Graph G, int x, int y);
bool Adjacent(const MGraph& G, int x, int y);
ArcNode *Adjacent(const ALGraph &G, int x, int y);

void Neighbors(Graph G, int x);
void Neighbors(MGraph &G, int x);
void Neighbors(ALGraph &G, int x);

void InsertVertex(Graph G, char x);
void InsertVertex(MGraph &G, char x);
void InsertVertex(ALGraph &G, char x);

void DeleteVertex(Graph G, Vertex x);
void DeleteVertex(MGraph &G, int x);
void DeleteVertex(ALGraph &G, int x);

bool AddEdge(Graph G, Vertex x, Vertex y);
void AddEdge(MGraph &G, int x, int y);
void AddEdge(ALGraph &G, int x, int y);

bool RemoveEdge(Graph G, Vertex x, Vertex y);
void RemoveEdge(MGraph &G, int x, int y);
void RemoveEdge(ALGraph &G, int x, int y);

int FirstNeighbor(Graph G, Vertex x);
int FirstNeighbor(const MGraph& G, int x);
int FirstNeighbor(const ALGraph& G, int x);

int NextNeighbor(Graph G, Vertex x, Vertex y);
int NextNeighbor(const MGraph& G, int x, int y);
int NextNeighbor(const ALGraph& G, int x, int y);

int Get_Edge_Value(Graph G, Vertex x, Vertex y);
int Get_Edge_Value(const MGraph& G, int x, int y);
int Get_Edge_Value(const ALGraph& G, int x, int y);

void Set_Edge_Value(Graph G, Vertex x, Vertex y, int v);
void Set_Edge_Value(MGraph &G, int x, int y, int v);
void Set_Edge_Value(const ALGraph& G, int x, int y, int v);



#endif //ALGORITHMEXERCISE_GRAPH_H
