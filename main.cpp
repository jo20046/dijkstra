#include <iostream>
#include "Graph.h"
#include "Dijkstratabelle.h"

int main() {

    Graph graph{10};
    graph.add_kante(0, 1, 3);
    graph.add_kante(0, 2, 5);
    graph.add_kante(0, 3, 1);
    graph.add_kante(1, 4, 1);
    graph.add_kante(2, 5, 4);
    graph.add_kante(2, 9, 3);
    graph.add_kante(3, 5, 2);
    graph.add_kante(4, 6, 1);
    graph.add_kante(5, 7, 1);
    graph.add_kante(5, 9, 3);
    graph.add_kante(6, 8, 2);
    graph.add_kante(6, 9, 4);
    graph.add_kante(7, 9, 3);
    graph.add_kante(8, 9, 3);
    graph.to_graphviz();


    Dijkstratabelle dijkstratabelle{graph};
    dijkstratabelle.dijkstra(0);
    dijkstratabelle.print();

    return 0;
}