//
// Created by hasee on 2021/10/17.
//

#ifndef ALGORITHMEXERCISE_GRAPH_H
#define ALGORITHMEXERCISE_GRAPH_H

#include <climits>
#include <vector>
#include <set>
#include <functional>
#include <iostream>

#define MaxVertexNum 100
#define Infinity INT_MAX
#define Unreachable (-1)

namespace basic {
    struct Edge {
        int x;
        int y;
        int weight;

        Edge(int x, int y, int weight = 1);

        Edge reverse();
    };

    std::string form(int i);
}

struct Graph {
    std::vector<char> _vertices;
    std::vector<basic::Edge> _edges;
    bool _directionality;

    Graph(std::vector<char> vertices, std::vector<basic::Edge> edges, bool directionality = true, int offset = 0);

    const std::vector<char> &vertices() const;
    std::vector<basic::Edge> edges() const;
};

struct Vertex;

struct MGraph {
    char Vex[MaxVertexNum];
    int Edge[MaxVertexNum][MaxVertexNum];
    int vexNum, arcNum;
    std::set<int> invalid;

    MGraph() = default;
    void Init(const std::vector<char> &vertex, const std::vector<basic::Edge>& edges);
    MGraph(const Graph &graph);

    void addVertex(char v, int i);
    int getIndex(char v);
    bool EdgeExist(int x, int y) const;

    int inDegree(int y);

    friend std::ostream &operator<<(std::ostream&, MGraph&);
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
    void Init(const std::vector<char> &vertex, const std::vector<basic::Edge>& edges);
    ALGraph(const Graph &graph);

    void append(int x, int y);
};

bool Adjacent(Graph G, int x, int y);
bool Adjacent(const MGraph& G, int x, int y);
ArcNode *Adjacent(const ALGraph &G, int x, int y);

void Neighbors(Graph G, int x);
void Neighbors(MGraph &G, int x);
void Neighbors(ALGraph &G, int x);

void InsertVertex(Graph G, char x);
void InsertVertex(MGraph &G, char v);
void InsertVertex(ALGraph &G, char x);

void DeleteVertex(Graph G, Vertex x);
void DeleteVertex(MGraph &G, char v);
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

void printVex(MGraph &g, int x, int from);

void BFS(MGraph &G, int v, bool visited[], const std::function<void(MGraph &g, int x, int from)> &
visit = printVex);

void BFSTraverse(MGraph &G, const std::function<void(MGraph&, int, int)>&
visit = printVex);

void DFSTraverse(MGraph &G, const std::function<void(MGraph&, int)> &
visit = [](MGraph &g, int x) { std::cout << g.Vex[x] << " "; });

std::vector<int> BFS_MinDistance(MGraph &G, int u);

std::vector<int> Dijkstra(MGraph &G, char vertex);

std::vector<std::vector<int>> Floyd(MGraph &G);

bool TopSort(MGraph &i);

#endif //ALGORITHMEXERCISE_GRAPH_H
