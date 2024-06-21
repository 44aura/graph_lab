#include "../headers/print_graph.h"
#include <algorithm>
#include <cmath>

void Print_graph::calculatePositions(int width, int height) {
    int radius = std::min(width, height) / 3;
    int centerX = width / 2;
    int centerY = height / 2;

    for (size_t i = 0; i < graph->vertices.size(); ++i) {
        double angle = 2 * M_PI * i / graph->vertices.size();
        graph->vertices[i].x = centerX + static_cast<int>(radius * cos(angle));
        graph->vertices[i].y = centerY + static_cast<int>(radius * sin(angle));
    }
}

void Print_graph::add_vertex(int num){
    if (std::find(graph->vertex_nums.begin(), graph->vertex_nums.end(), num) == graph->vertex_nums.end()){
            graph->vertex_nums.push_back(num);
            graph->vertices[num - 1] = Vertex(num);
        }
}

void Print_graph::add_edge(int i, int u, int v){
    graph->edges[i] = Edge(&graph->vertices[u - 1], &graph->vertices[v - 1]);
}

void Print_graph::graph_constructor(){
    const int width = 300;
    const int height = 300;
    bmp->image_settings(width, height);
    calculatePositions(width, height);

    for (Vertex& vertex : graph->vertices) {
        bmp->draw_vertex(vertex.x, vertex.y);
        bmp->draw_num(vertex.x, vertex.y, vertex.number);
    }
 
    for (Edge& edge : graph->edges) {
        bmp->draw_line(edge.u->x, edge.u->y, edge.v->x, edge.v->y);
    }

    bmp->file_write("out.bmp");
}

Print_graph::~Print_graph(){
    delete bmp;
    delete graph;
}