#include "../headers/BMP.h"
#include "../headers/graph.h"

#pragma pack(push, 1)
struct Print_graph{
private:
    BMP* bmp = new BMP;
    Graph* graph = new Graph;
public:
    void graph_constructor();
    void calculatePositions(int width, int height);
    void graph_resize(int V, int E){graph->resize(V, E);}
    void add_vertex(int num);
    void add_edge(int i, int u, int v);
    ~Print_graph();
};
#pragma pack(pop)