//
//  main.cpp
//  TP 2 BFS & DFS (2)
//
//  Created by Jeanne Alexandra Brunard on 20/03/2020.
//  Copyright © 2020 Jeanne Alexandra Brunard. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include "graphe.h"
#include "sommet.h"
#include <fstream>
#include <iostream>
#include<vector>

Sommet::Sommet()
{
    num = 0;
    marquage = 0;
}


void Graphe :: chargement()
{
    std::ifstream ifs{"fichier.txt"};
    
    int nbr1=0;
    int nbr2=0;
    
    Graphe graphe;
    Sommet sommet;
    
        if(!ifs)
        {
            std::cout << "Probleme ouverture fichier"<<std::endl;
            ifs.close();
        }
    
        else
        {

            ifs>>orient; // orientation
            ifs>>ordre; // nombre de sommet
            ifs>>taille; // nombre d'arrete
            
            if(orient ==0)
            {
                std::cout<<"le graphe est non orienté"<<std::endl;
            }
            
            else
            {
                std::cout<<"le graphe est orienté"<<std::endl;
            }
            
            std::cout<<"la taille est "<<taille<<std::endl;
             
            
            // Creation de la listes des sommets
            std::cout<<"ordre="<<ordre<<std::endl;
            
            
            for(int i=0;i<ordre;i++)
            {
                // creation vector
                Sommet *nouv = new Sommet();
                l_sommets.push_back(nouv);
                
                l_sommets[i]->num=i;
            }

            
            // classement liste
            
            for (int i=0;i<taille;i++) // on parcours les lignes
            {
                ifs>>nbr1; ifs>>nbr2;
                
                for(int j=0;j<ordre;j++) // on parcours les sommets
                {
                    
                    if(nbr1==l_sommets[j]->num) // si c'est égale au sommet
                    {
                        
                        // creation vector
                        Sommet *nouv2 = new Sommet();
                        l_sommets[j]->l_adj.push_back(nouv2);

                        std::cout<<"i="<<i<<std::endl;
                        std::cout<<"j="<<j<<std::endl;
                        
                        std::cout<<"apa avant = "<<l_sommets[j]->apa<<std::endl;
                        
                        l_sommets[j]->l_adj[l_sommets[j]->apa]->num = nbr2; // on met le nbr2 dans la liste des pred
                        
                        l_sommets[j]->apa=l_sommets[j]->apa+1; // on ajoute 1 car le sommet est apparu
                        
                        
                      //  l_sommets[nbr2+1]->apa=l_sommets[nbr2+1]->apa+1;
                        
                         std::cout<<"apa apres = "<<l_sommets[j]->apa<<std::endl;
                    }
                }
                
            }
            
            // Affichage liste
            
            for (size_t i=0; i<ordre; i++)
            {
                std::cout<<"    sommet "<<l_sommets[i]->num << ":";
                
                for(size_t j=0;j<l_sommets[i]->apa;j++)
                {
                    std::cout<<l_sommets[i]->l_adj[j]->num;
                }
                
                std::cout<<std::endl;
               
            }
           
             ifs.close(); // fermeture fichier
          
        }
   
}


void Graphe :: affichage() const
{
    
}





int main(int argc, const char * argv[]) {
    
    Graphe graphe;
    
    
    
    graphe.chargement();
    
    return 0;
}
