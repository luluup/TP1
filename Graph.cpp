#include "Graph.h"

#include <fstream>
#include <iostream>
#include <vector>

// Constructeur surcharge
Graph::Graph():NbrSommet(0),mat(0)
{
}

// Destructeur
Graph::~Graph()
{

}
// Allouer la matrice d’adjacence dynamique du graphe de « ordre » sommets et instancier le vecteur de sommets
bool** Graph::allocation(int NbrSommet)
{
    int a;
    bool** mat; // Matrice booleene
    mat = new bool* [NbrSommet]; //allocation dynamique
    for( a=0; a<NbrSommet; a++) //Parcours
    {
        mat[a]= new bool [NbrSommet];
    }
    return mat;
}

//récupérer dans un fichier texte les données pour les mémoriser
bool** Graph::recuperation(bool **mat)
{
    int NbrSommet;
    std::string monFichier1 = "Matrice.txt" ; //Stockage dans la chaine monFichier2
    std::ifstream fichier(monFichier1.c_str(),std::ios::in); //Fichier contenant la matrice adjacente

    if(fichier) //si l'ouverture a fonctionné
    {
        fichier>>NbrSommet; //on lit le fichier et on stocke ce qui est lu
        bool nb;
        mat=allocation(NbrSommet);
        int a,b;
        for( a=0; a<6; a++) //on parcourt la premiere matrice
        {
            for(b=0; b<6; b++) //on parcourt la deuxieme matrice
            {
                fichier >> nb; //lecture
                mat[a][b]=nb;
            }
        }
        fichier.close();  // On ferme le fichier
    }
    else
        std::cerr<<"Erreur ouverture fichier"<<std::endl;

    int a,b;
    for( a=0; a<6; a++)
    {
        for( b=0; b<6; b++)
        {
            std::cout<<mat[a][b]; //affichage de la matrice sur la console

        }
        std::cout << "\n" << std::endl; //saut a la ligne pour bien visualiser la matrice adjacente
    }

    std::string monFichier2 = "Personnages.txt"; //Stockage dans la chaine monFichier2
    std::ifstream A(monFichier2.c_str(),std::ios::in); //Fichier contenant les noms des personnes

    std::string Prenom;

    if(A)
    {
        for( a=0; a<6; a++)
        {
            A>>Prenom;
            sommet.push_back(Prenom);
        }
    }
    else
    {
        std::cerr<<"Erreur ouverture fichier"<<std::endl;
    }
    affichage(sommet, mat); //appel de la fonction
    return mat;


}
// On affiche les jeux d’influences des personnes
void Graph::affichage(std::vector <std::string> sommet,bool **mat)
{
    int a,b;
    for( a=0; a<6; a++) //On parcourt la matrice
    {
        for( b=0; b<6; b++)
        {
            if(mat[a][b]==1)
            {
                std::cout<<sommet[a]<<" influence "<<sommet[b]<<"\n"<<std::endl; //affichage du jeu d'influence
            }
        }
    }
}

