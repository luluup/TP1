#ifndef ARETE_H_INCLUDED
#define ARETE_H_INCLUDED

#include "Sommet.h"

class Arete
{
    Sommet depart;
    Sommet arrivee;
    Arete( Sommet depart, Sommet arrivee);
    ~Arete();
};

#endif // ARETE_H_INCLUDED
