#include <iostream>
#include <fstream>
#include "../headers/print_graph.h"

int main(){
    Print_graph printer;
    std::ifstream inputf("example.txt");
    int V, E;
    inputf >> V >> E;  
    printer.graph_resize(V, E);
    for (int i = 0; i < E; i ++){
        int u, v;
        inputf >> u >> v;
        printer.add_vertex(u);
        printer.add_vertex(v);
        printer.add_edge(i, u, v);
    }
    inputf.close();

    printer.graph_constructor();
    return 0;
}