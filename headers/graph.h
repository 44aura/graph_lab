#include <string>
#include <vector>
#include <utility>
#include <iostream>

#pragma pack(push, 1)
struct Vertex{
    Vertex(){number = 0;}
    Vertex(int num){number = num;}
    int number;
    int x, y {0};
};

struct Edge{
    Edge(): u(nullptr), v(nullptr){;}
    Edge(Vertex* v1, Vertex* v2): u(v1), v(v2){;}
    Vertex* u;
    Vertex* v;
};

struct Graph{
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    std::vector<int> vertex_nums;

    void resize(int V, int E){vertices.resize(V), edges.resize(E);}
};
#pragma pack(pop)