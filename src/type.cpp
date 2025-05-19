#include "type.h"


#include <iostream>

void freePath(path &Gpath) {
    for (int i = 0; i < Gpath.t; i++) {
        int rows = Gpath.dim[0];
        for (int j = 0; j < rows; j++) {
            delete[] Gpath.g[i][j]; // ligne de str[]
        }
        delete[] Gpath.g[i]; // ligne
    }
    delete[] Gpath.g; // tableau principal
    Gpath.g = nullptr;
    Gpath.t = 0;
}

grid copieGrid(grid original, arr2 dim) {
    int rows = dim[0];
    int cols = dim[1];

    grid newGrid = new str*[rows];
    for (int i = 0; i < rows; ++i) {
        newGrid[i] = new str[cols];
        for (int j = 0; j < cols; ++j) {
            newGrid[i][j] = original[i][j];
        }
    }

    return newGrid;
}

void afficherSgrid(sgrid& g) {
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
    for (int i = 0; i < g.taille[0]; ++i) {
        for (int j = 0; j < g.taille[1]; ++j) {
            std::cout << g.val[i][j];
        }
        std::cout << "\n";
    }
}

voiture getvoiture(sgrid plateau,str id){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==id){return plateau.v[i];}
    }
    return plateau.v[0];  //normalement jamais arrivé mais au cas ou pour quand meme return qlq chose 
}

int getIndexVoiture(sgrid plateau,str id){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==id){return i;}
    }
    return 0;  //normalement jamais arrivé mais au cas ou pour quand meme return qlq chose 
}

arr2* getCoordVoiture(voiture v){
    arr2* c=new arr2[v.taille];
    if(v.ori=="horizontale"){
        for(int i=0;i<v.taille;i++){
            c[i]={v.coord[0],v.coord[1]+i};}
    }
    else{
        for(int i=0;i<v.taille;i++){
            c[i]={v.coord[0]+i,v.coord[1]};
        }
    }
    return c;
}

bool victoire(sgrid plateau){
    int x=plateau.fin[0];int y=plateau.fin[1];
    return plateau.val[x][y]==plateau.v_dep;
}

bool canMove(sgrid plateau,voiture v,char dir){
    arr2* v_coord=getCoordVoiture(v);
    if(v.ori=="horizontale"){
        if(dir=='d'){return plateau.val[v_coord[v.taille-1][0]][v_coord[v.taille-1][1]+1]==emptychr;}
        if(dir=='g'){return plateau.val[v_coord[0][0]][v_coord[0][1]-1]==emptychr;}
    }else{
        if(dir=='b'){return plateau.val[v_coord[v.taille-1][0]+1][v_coord[v.taille-1][1]]==emptychr;}
        if(dir=='h'){return plateau.val[v_coord[0][0]-1][v_coord[0][1]]==emptychr;}
    }     
    return false;
} 

void addValuePath(path &Gpath, grid g) {
    // Alloue un nouveau tableau de grid avec +1 place
    grid* new_g = new grid[Gpath.t + 1];

    // Copie tous les anciens grids (en profondeur)
    for (int i = 0; i < Gpath.t; i++) {
        new_g[i] = copieGrid(Gpath.g[i], Gpath.dim);
    }

    // Copie du nouveau grid (état actuel)
    new_g[Gpath.t] = copieGrid(g, Gpath.dim);

    // Libère l'ancienne mémoire
    for (int i = 0; i < Gpath.t; i++) {
        int rows = Gpath.dim[0];
        for (int j = 0; j < rows; j++) {
            delete[] Gpath.g[i][j]; // str[] à chaque ligne
        }
        delete[] Gpath.g[i]; // ligne complète
    }
    delete[] Gpath.g; // tableau de grids

    // Remplace les valeurs dans Gpath
    Gpath.g = new_g;
    Gpath.t += 1;
}

bool equalGrid(grid g1,grid g2,arr2 dim){
    int tailleX=dim[0];
    int tailleY=dim[1];

    for(int i=0;i<tailleX;i++){
        for(int j=0;j<tailleY;j++){
            if(g1[i][j]!=g2[i][j]){return false;}
        }
    }

    return true;
}

bool doubleGridList(path l_grid,grid g){   //cherche si le dernier element est deja dans la list
    for (int i = 0; i < l_grid.t - 1; i++) {
        if (equalGrid(l_grid.g[i], g,l_grid.dim)) {
            return true;
        }
    }
    return false;
}

