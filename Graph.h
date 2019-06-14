//
// Created by Enthöfer Joshua on 2019-06-13.
//

#ifndef DIJKSTRA_GRAPH_H
#define DIJKSTRA_GRAPH_H

#include <vector>

class Graph {

public:
    explicit Graph(int anzahl_knoten);

    void add_kante(int start, int ziel, int gewicht);

    void to_graphviz();

    int get_anzahl_knoten();

    int get_anzahl_kanten();

    bool hat_verbindung(int start, int ziel);

    int get_kantengewicht(int start, int ziel);

private:
    int anzahl_knoten_;
    std::vector<int> knoten_;
    std::vector<std::vector<int>> kanten_;

};


#endif //DIJKSTRA_GRAPH_H
