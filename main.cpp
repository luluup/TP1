#include <iostream>
#include "Sommet.h"
#include "Graph.h"
#include "Arete.h"
#include <fstream>

using namespace std;


int main()
{
    Graph personnage; //Instanciation de l'Objet de la classe Graph
    bool** mat; //matrice adjacente
    std::cout << "Voici la matrice suivi du jeu d'influence" << std::endl;
    personnage.recuperation(mat); // Recupere les donnees du fichier et affiche les jeux d'influence de l'objet
}
