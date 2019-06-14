//
// Created by Enthöfer Joshua on 2019-06-14.
//

#ifndef DIJKSTRA_DIJKSTRATABELLE_H
#define DIJKSTRA_DIJKSTRATABELLE_H

#include <vector>
#include "Graph.h"

class Dijkstratabelle {

public:
    explicit Dijkstratabelle(Graph graph);

    void print();

    void dijkstra(int start_knoten);


private:
    Graph graph_ = Graph(0);
    std::vector<int> knoten_;
    std::vector<int> gesamtdistanz_;
    std::vector<int> vorgaenger_;

    std::vector<std::vector<int>> get_nachbarn_mit_distanzen(int aktueller_knoten, int aktuelle_distanz,
                                                             std::vector<int> besuchte_knoten,
                                                             std::vector<int> &erreichbare_knoten);
    void distanzen_und_vorgaenger_updaten(const std::vector<std::vector<int>>& distanzen, int aktueller_knoten);

    int neuen_knoten_auswaehlen(std::vector<int> besuchte_knoten, std::vector<int> erreichbare_knoten);

};


#endif //DIJKSTRA_DIJKSTRATABELLE_H
