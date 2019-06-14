//
// Created by Enthöfer Joshua on 2019-06-13.
//

#include <fstream>
#include "Graph.h"

Graph::Graph(int anzahl_knoten) {
    this->anzahl_knoten_ = anzahl_knoten;
    for(int i = 0; i < anzahl_knoten_; i++) {
        knoten_.push_back(i);
    }
}

void Graph::add_kante(int start, int ziel, int gewicht) {
    kanten_.push_back({start, ziel, gewicht});
}

void Graph::to_graphviz() {
    std::ofstream out;
    out.open("dijkstra.gv");
    out << "graph {" << std::endl;
    for (auto& kante : kanten_) {
        out << "  v" << kante.at(0) << " -- v" << kante.at(1) << " [label=" << kante.at(2) << ", weight=" << kante.at(2) << "]" << std::endl;
    }
    out << "}" << std::endl;
    out.close();
}

int Graph::get_anzahl_knoten() {
    return knoten_.size();
}

int Graph::get_anzahl_kanten() {
    return kanten_.size();
}

bool Graph::hat_verbindung(int start, int ziel) {
    for (int i = 0; i < get_anzahl_kanten(); i++) {
        if ((kanten_.at(i).at(0) == start && kanten_.at(i).at(1) == ziel) ||
            (kanten_.at(i).at(1) == start && kanten_.at(i).at(0) == ziel)) {
            return true;
        }
    }
    return false;
}

int Graph::get_kantengewicht(int start, int ziel) {
    for (int i = 0; i < get_anzahl_kanten(); i++) {
        if ((kanten_.at(i).at(0) == start && kanten_.at(i).at(1) == ziel) ||
            (kanten_.at(i).at(1) == start && kanten_.at(i).at(0) == ziel)) {
            return kanten_.at(i).at(2);
        }
    }
    return -1;
}
