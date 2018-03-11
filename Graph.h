#ifndef GRAPH_H_INCLUDED
#define GRAPH_H_INCLUDED

#include <iostream>
#include <vector>
#include "Sommet.h"
#include "Arete.h"


class Graph
{
    public:

    // Attributs
    int NbrSommet; //nombre de sommets du graph
    std::vector <std::string> sommet;
    bool ** mat;   // On utilise une matrice d’adjacence dynamique de booleens

    // Constructeur & destructeur
    Graph();
    ~Graph();

    // Methodes
    bool** allocation(int NbrSommet);
    bool** recuperation(bool **mat);
    void affichage(std::vector <std::string> sommet,bool** mat);
};


#endif // GRAPH_H_INCLUDED
