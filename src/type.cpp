#include "type.h"


#include <iostream>

void afficherSgrid(const sgrid& g) {
    std::cout << "Nom : " << g.nom << "\n";
    std::cout << "Nombre de voitures : " << g.nb_voit << "\n";
    std::cout << "Voiture de depart : " << g.v_dep << "\n";
    std::cout << "Taille : " << g.taille[0] << " x " << g.taille[1] << "\n";
    std::cout << "Sortie : (" << g.fin[0] << ", " << g.fin[1] << ")\n\n";

    std::cout << "Liste des voitures :\n";
    for (int i = 0; i < g.nb_voit; ++i) {
        const voiture& v = g.v[i];
        std::cout << "- ID : " << v.id
                  << ", Couleur : " << v.color
                  << ", Coord : (" << v.coord[0] << ", " << v.coord[1] << ")"
                  << ", Taille : " << v.taille
                  << ", Orientation : " << v.ori << "\n";
    }

    std::cout << "\nGrille :\n";
    for (int i = 0; i < g.taille[1]; ++i) {
        for (int j = 0; j < g.taille[0]; ++j) {
            std::cout << g.val[i][j];
        }
        std::cout << "\n";
    }
}