//
//  graphe.h
//  TP 2 BFS & DFS (2)
//
//  Created by Jeanne Alexandra Brunard on 20/03/2020.
//  Copyright © 2020 Jeanne Alexandra Brunard. All rights reserved.
//

#ifndef graphe_h
#define graphe_h
#include "sommet.h"
#include <vector>


class Graphe
{
    private :

    std::vector<Sommet*> l_sommets; // liste de tous les sommets
    int orient;
    int ordre; // nombre de sommets a partir de 0
    int taille; // nombre d'arrete
    
    
    
    public :
    
    void affichage() const;
    void chargement();
    void cree();
    
};


#endif /* graphe_h */
