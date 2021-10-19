//
// Created by hasee on 2021/10/17.
//

#ifndef ALGORITHMEXERCISE_GRAPH_H
#define ALGORITHMEXERCISE_GRAPH_H

#include <climits>
#include <vector>

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

    MGraph() = default;
    MGraph(std::vector<char> vertex, std::vector<std::vector<int>> edges);
};

typedef char VertexType;

struct ArcNode {
    int adjVex;
    ArcNode *next;

    ArcNode(int vex, ArcNode *next = NULL);
};

struct VNode {
    VertexType data;
    ArcNode *first;
};

typedef VNode AdjList[MaxVertexNum];

struct ALGraph {
    AdjList vertices;
    int vexNum, arcNum;

    ALGraph() = default;
    ALGraph(std::vector<char> vertex, std::vector<std::vector<int>> edges);

    void append(int x, int y);
};

bool Adjacent(Graph G, int x, int y);
bool Adjacent(MGraph G, int x, int y);
bool Adjacent(ALGraph G, int x, int y);

void Neighbors(Graph G, int x);
void Neighbors(MGraph G, int x);
void Neighbors(ALGraph G, int x);

void InsertVertex(Graph G, char x);
void InsertVertex(MGraph G, char x);
void InsertVertex(ALGraph G, char x);

void DeleteVertex(Graph G, Vertex x);
void DeleteVertex(MGraph G, int x);
void DeleteVertex(ALGraph G, int x);

bool AddEdge(Graph G, Vertex x, Vertex y);
bool RemoveEdge(Graph G, Vertex x, Vertex y);
int FirstNeighbor(Graph G, Vertex x);
int NextNeighbor(Graph G, Vertex x, Vertex y);
int Get_Edge_Value(Graph G, Vertex x, Vertex y);
bool Set_Edge_Value(Graph G, Vertex x, Vertex y);



#endif //ALGORITHMEXERCISE_GRAPH_H
