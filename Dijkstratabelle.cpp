#include <utility>
#include <iostream>
#include <iomanip>

//
// Created by Enthöfer Joshua on 2019-06-14.
//

#include "Dijkstratabelle.h"

Dijkstratabelle::Dijkstratabelle(Graph graph) {
    graph_ = std::move(graph);
    int size = graph_.get_anzahl_knoten();
    for (int i = 0; i < size; i++) {
        knoten_.push_back(i);
    }
}

void Dijkstratabelle::print() {

    std::cout << std::setw(15) << "Knoten " << '|';
    for (int knoten : knoten_) {
        std::cout << std::setw(3) << knoten << '|';
    }
    std::cout << std::endl;

    std::cout << std::setw(15) << "Gesamtdistanz " << '|';
    for (int distanz : gesamtdistanz_) {
        if (distanz != std::numeric_limits<int>::max()) {
            std::cout << std::setw(3) << distanz << '|';
        } else {
            std::cout << std::setw(5) << u8"\u221e" << '|';
        }
    }
    std::cout << std::endl;

    std::cout << std::setw(16) << "Vorgänger " << '|';
    for (int vorgaenger : vorgaenger_) {
        if (vorgaenger != -1) {
            std::cout << std::setw(3) << vorgaenger << '|';
        } else {
            std::cout << std::setw(4) << u8"\u0444" << '|';
        }
    }
    std::cout << std::endl;
}

void Dijkstratabelle::dijkstra(int start_knoten) {

    // bestehende Inhalte löschen
    gesamtdistanz_.clear();
    vorgaenger_.clear();

    // Tabellen initialisieren
    int size = knoten_.size();
    for (int i = 0; i < size; i++) {
        gesamtdistanz_.push_back(std::numeric_limits<int>::max());
        vorgaenger_.push_back(-1);
    }
    gesamtdistanz_.at(start_knoten) = 0;


    // Dijkstra
    std::vector<int> besuchte_knoten;
    std::vector<int> erreichbare_knoten;
    int aktueller_knoten = start_knoten;
    int aktuelle_distanz = 0;
    while (besuchte_knoten.size() < knoten_.size() && aktueller_knoten != -1) {
        besuchte_knoten.push_back(aktueller_knoten);
        aktuelle_distanz = gesamtdistanz_.at(aktueller_knoten);
        std::vector<std::vector<int>> nachbardistanzen = get_nachbarn_mit_distanzen(aktueller_knoten, aktuelle_distanz,
                                                                                    besuchte_knoten,
                                                                                    erreichbare_knoten);
        distanzen_und_vorgaenger_updaten(nachbardistanzen, aktueller_knoten);
        aktueller_knoten = neuen_knoten_auswaehlen(besuchte_knoten, erreichbare_knoten);

    }
}

std::vector<std::vector<int>>
Dijkstratabelle::get_nachbarn_mit_distanzen(int aktueller_knoten, int aktuelle_distanz,
                                            std::vector<int> besuchte_knoten,
                                            std::vector<int> &erreichbare_knoten) {
    std::vector<std::vector<int>> result;
    for (int nachbar : knoten_) {
        // Nachbar darf noch nicht besucht worden sein
        // Nachbar muss Verbindung zum aktuellen Knoten haben
        if ((!(std::find(besuchte_knoten.begin(), besuchte_knoten.end(), nachbar) != besuchte_knoten.end())) &&
            (graph_.hat_verbindung(aktueller_knoten, nachbar))) {
            result.push_back({nachbar, aktuelle_distanz + graph_.get_kantengewicht(aktueller_knoten, nachbar)});
            erreichbare_knoten.push_back(nachbar);
        }
    }
    return result;
}

void Dijkstratabelle::distanzen_und_vorgaenger_updaten(const std::vector<std::vector<int>> &distanzen,
                                                       int aktueller_knoten) {
    for (const auto &value : distanzen) {
        int knoten = value.at(0);
        int distanz = value.at(1);
        if (gesamtdistanz_.at(knoten) > distanz) {
            gesamtdistanz_.at(knoten) = distanz;
            vorgaenger_.at(knoten) = aktueller_knoten;
        }
    }
}

int Dijkstratabelle::neuen_knoten_auswaehlen(std::vector<int> besuchte_knoten, std::vector<int> erreichbare_knoten) {
    int result = -1;
    int distanz = std::numeric_limits<int>::max();
    for (int knoten : knoten_) {
        if (!(std::find(besuchte_knoten.begin(), besuchte_knoten.end(), knoten) != besuchte_knoten.end()) &&
            (std::find(erreichbare_knoten.begin(), erreichbare_knoten.end(), knoten) != erreichbare_knoten.end()) &&
            gesamtdistanz_.at(knoten) < distanz) {
            result = knoten;
            distanz = gesamtdistanz_.at(knoten);
        }
    }
    return result;
}
