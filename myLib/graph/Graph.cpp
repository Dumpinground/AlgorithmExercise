//
// Created by hasee on 2021/10/17.
//

#include "Graph.h"

#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

basic::Edge::Edge(int x, int y, int weight) :
        x(x), y(y), weight(weight) {}

basic::Edge basic::Edge::reverse() {
    return {y, x, weight};
}

string basic::form(int i) {
    return i == Infinity ? "~" : to_string(i);
}

Graph::Graph(vector<char> vertices, vector<basic::Edge> edges, bool directionality, int offset) :
        _vertices(std::move(vertices)), _edges(std::move(edges)), _directionality(directionality) {
    if (offset) {
        for (auto &e: _edges) {
            e.x += offset;
            e.y += offset;
        }
    }
}

const std::vector<char> &Graph::vertices() const {
    return _vertices;
}

std::vector<basic::Edge> Graph::edges() const {
    auto edges = _edges;
    if (!_directionality)
        for (auto e: _edges) {
            edges.push_back( e.reverse() );
        }
    return edges;
}

void MGraph::Init(const vector<char> &vertex, const vector<basic::Edge>& edges) {
    vexNum = vertex.size();

    for (int i = 0; i < vexNum; ++i) {
        Vex[i] = vertex[i];
    }

    arcNum = edges.size();

    for (int i = 0; i < MaxVertexNum; ++i)
        for (int j = 0; j < MaxVertexNum; ++j)
            Edge[i][j] = i == j ? 0 : Infinity;

    for (auto edge : edges) {
        Edge[edge.x][edge.y] = edge.weight;
    }
}

MGraph::MGraph(const Graph &graph) {
    Init(graph.vertices(), graph.edges());
}

std::ostream &operator<<(ostream &out, MGraph &G) {
    int space = 5;

    out << setw(space) << "";
    for (int i = 0; i < G.vexNum; ++i) {
        out << setw(space) << (G.invalid.find(i) != G.invalid.end() ? 'X' : G.Vex[i]);
    }
    out << endl;
    for (int i = 0; i < G.vexNum; ++i) {
        out << setw(space) << (G.invalid.find(i) != G.invalid.end() ? 'X' : G.Vex[i]);
        for (int j = 0; j < G.vexNum; ++j) {
            out << setw(space) << basic::form(G.Edge[i][j]);
        }
        out << endl;
    }
    return out;
}

void MGraph::addVertex(char v, int i) {
    Vex[i] = v;
    Edge[i][i] = 0;
}

int MGraph::getIndex(char v) {
    for (int i = 0; i < vexNum; ++i) {
        if (Vex[i] == v && invalid.find(i) == invalid.end())
            return i;
    }
    return Unreachable;
}

bool MGraph::EdgeExist(int x, int y) const {
    return Edge[x][y] && Edge[x][y] != Infinity;
}

ArcNode::ArcNode(int vex, ArcNode *next, int w) :
adjVex(vex), next(next), weight(w) {}

void ALGraph::Init(const vector<char> &vertex, const vector<basic::Edge>& edges) {
    vexNum = vertex.size();

    for (int i = 0; i < vexNum; ++i) {
        vertices[i] = {vertex[i]};
    }

    arcNum = edges.size();

    for (auto edge : edges) {
        append(edge.x, edge.y);
    }
}

ALGraph::ALGraph(const Graph &graph) {
    Init(graph.vertices(), graph.edges());
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

void InsertVertex(MGraph &G, char v) {
    if (G.invalid.empty()) {
        G.addVertex(v, G.vexNum++);
    } else {
        auto it = G.invalid.begin();
        G.addVertex(v, *it);
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

void DeleteVertex(MGraph &G, char v) {

    int x = G.getIndex(v);
    if (x == Unreachable)
        return;

    G.invalid.insert(x);
    for (int i = 0; i < G.vexNum; ++i) {
        G.Edge[x][i] = Infinity;
        G.Edge[i][x] = Infinity;
    }
}

void DeleteVertex(ALGraph &G, int x) {
    G.invalid.insert(x);
    G.vertices[x].first = NULL;
    for (int i = 0; i < G.vexNum; ++i) {
        RemoveEdge(G, i, x);
    }
}

void AddEdge(MGraph &G, int x, int y) {
    G.Edge[x][y] = 1;
}

void AddEdge(ALGraph &G, int x, int y) {
    G.append(x, y);
}

void RemoveEdge(MGraph &G, int x, int y) {
    G.Edge[x][y] = Infinity;
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
        if (G.EdgeExist(x, i))
            return i;
    }
//    for (int i = 0; i < G.vexNum; ++i) {
//        if (G.Edge[i][x])
//            return i;
//    }
    return Unreachable;
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
    return Unreachable;
}

int NextNeighbor(const MGraph& G, int x, int y) {
    for (int i = y + 1; i < G.vexNum; ++i) {
        if (G.EdgeExist(x, i))
            return i;
    }
    return Unreachable;
}

int NextNeighbor(const ALGraph& G, int x, int y) {
    auto p = G.vertices[x].first;
    while (p && p->adjVex != y) {
        p = p->next;
    }
    if (p && p->next)
        return p->next->adjVex;
    else
        return Unreachable;
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

void printVex(MGraph &g, int x, int from) {
    std::cout << g.Vex[x] << " ";
}

void BFS(MGraph &G, int v, bool visited[], const function<void(MGraph &g, int x, int from)> &visit) {

    queue<int> Q;

    auto mark = [&](int x) {
        visited[x] = true;
        Q.push(x);
    };

    visit(G, v, Unreachable);
    mark(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        for (int i = FirstNeighbor(G, v); i != -1; i = NextNeighbor(G, v, i)) {
            if (!visited[i]) {
                visit(G, i, v);
                mark(i);
            }
        }
    }

}

void BFSTraverse(MGraph &G, const function<void(MGraph &, int, int)> &visit) {

    bool visited[G.vexNum];
    for (auto d : G.invalid) {
        visited[d] = true;
    }
    for (int i = 0; i < G.vexNum; ++i) {
        if (!visited[i])
            BFS(G, i, visited, visit);
    }
}

void DFS(MGraph &G, int v, bool visited[], const std::function<void(MGraph &, int)> &visit) {

    auto mark = [&visited](int v) {
        visited[v] = true;
    };

    visit(G, v);
    mark(v);
    for (int i = FirstNeighbor(G, v); i != Unreachable; i = NextNeighbor(G, v, i)) {
        if (!visited[i])
            DFS(G, i, visited, visit);
    }
}

void DFSTraverse(MGraph &G, const function<void(MGraph &, int)> &visit) {

    bool visited[G.vexNum];
    for (auto d : G.invalid) {
        visited[d] = true;
    }
    for (int i = 0; i < G.vexNum; ++i) {
        if (!visited[i])
            DFS(G, i, visited, visit);
    }
}

vector<int> BFS_MinDistance(MGraph &G, int u) {
    int d[G.vexNum];
    vector<int> path(G.vexNum);
    for (int i = 0; i < G.vexNum; ++i) {
        d[i] = Infinity;
        path[i] = -1;
    }

    bool visited[G.vexNum];
    for (int i = 0; i < G.vexNum; ++i) {
        visited[i] = false;
    }
    for (auto deleted : G.invalid) {
        visited[deleted] = true;
    }

    BFS(G, u, visited, [&](MGraph &g, int v, int from) {
        if (from == Unreachable) {
            d[v] = 0;
        } else {
            d[v] = d[from] + 1;
            path[v] = from;
        }
    });

    cout << "distance from " << u << endl;
    for (int i = 0; i < G.vexNum; ++i) {
        cout << G.Vex[i] << ":  " << basic::form(d[i]) << " <- " << path[i] << endl;
    }
    cout << endl;
    return path;
}

void findPath(MGraph &G, char v, const vector<int> &path, const vector<int> &dist) {
    cout << "path:" << endl;

    for (int i = 0; i < G.vexNum; ++i) {
        int j = i;
        while (path[j] != Unreachable) {
            cout << "v" << G.Vex[j] << "<-";
            j = path[j];
        }

        cout << "v" << v << " : " + basic::form(dist[i]) << endl;
    }
}

void findPath(MGraph &G, const vector<vector<int>> &path, const vector<vector<int>> &dist) {

    auto vex = [&](int v)->string {
        return new char[2]{'v', G.Vex[v]};
    };

    cout << "path:" << endl;

    for (int i = 0; i < G.vexNum; ++i) {
        for (int j = 0; j < G.vexNum; ++j) {
            cout << setw(3) << path[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    function<string(int, int)> drawPath;
    drawPath = [&](int start, int stop)->string {
        int t = path[start][stop];
        if (t == Unreachable)
            return vex(start) + "->" + vex(stop);
        else
            return drawPath(start, t) + " " + drawPath(t, stop);
    };

    int v = 0;
    cout << vex(v) << ":" << endl;
    for (int stop = 0; stop < G.vexNum; ++stop) {
        if (dist[v][stop] != Infinity)
            cout << drawPath(v, stop) << " " << dist[v][stop] << endl;
    }
}

vector<int> Dijkstra(MGraph &G, char vertex) {

    int v = G.getIndex(vertex);

    vector<bool> final(G.vexNum, false);
    vector<int> dist(G.vexNum, Infinity), path(G.vexNum, Unreachable);

    dist[v] = 0;
    final[v] = true;

    int count = 1;
    while (count++ < G.vexNum) {

        for (int i = FirstNeighbor(G, v); i != Unreachable; i = NextNeighbor(G, v, i)) {
            if (!final[i]) {
                int newDist = dist[v] + G.Edge[v][i];
                if (newDist < dist[i]) {
                    dist[i] = newDist;
                    path[i] = v;
                }
            }
        }

        struct {
            int vertex;
            int dist;

            bool empty() const { return vertex == Unreachable; }
        } next{Unreachable, Infinity};

        for (int i = 0; i < G.vexNum; ++i) {
            if (!final[i] && dist[i] < next.dist)
                next = {i, dist[i]};
        }

        if (!next.empty()) {
            v = next.vertex;
            final[v] = true;
        }

    }

    findPath(G, vertex, path, dist);

    return path;
}

vector<vector<int>> Floyd(MGraph &G) {
    vector<vector<int>> dist(G.vexNum, vector<int>(G.vexNum));
    for (int i = 0; i < G.vexNum; ++i) {
        for (int j = 0; j < G.vexNum; ++j) {
            dist[i][j] = G.Edge[i][j];
        }
    }
    
    auto distPrint = [&](bool on = true) {
        if (!on)
            return;
        cout << endl;
        for (int i = 0; i < G.vexNum; ++i) {
            for (int j = 0; j < G.vexNum; ++j) {
                cout << basic::form(dist[i][j]) << "  ";
            }
            cout << endl;
        }
    };
    
    vector<vector<int>> path(G.vexNum, vector<int>(G.vexNum, Unreachable));
    distPrint(false);
    for (int transit = 0; transit < G.vexNum; ++transit)
        for (int start = 0; start < G.vexNum; ++start)
            for (int stop = 0; stop < G.vexNum; ++stop) {
                int &direct = dist[start][stop];
                int curve = dist[start][transit] + dist[transit][stop];
                if (curve > 0 && direct > curve) {
                    direct = curve;
                    path[start][stop] = transit;
                    distPrint(false);
                }
            }


    findPath(G, path, dist);
    
    return path;
}

