#include "type.h"







void printVector(std::vector<Move> v){
    for(unsigned int i=0;i<v.size();i++){
        std::cout<<v[i][0]<<v[i][1]<<" ";
    }
    std::cout<<std::endl;
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

sgrid copieSgrid(sgrid original){
    sgrid copy;
    copy.fin=original.fin;
    copy.nb_voit=original.nb_voit;
    copy.nom=original.nom;
    copy.taille=original.taille;
    copy.v_dep=original.v_dep;

    copy.v = new voiture[copy.nb_voit];
    for(int i=0;i<copy.nb_voit;i++){
        copy.v[i]=original.v[i];
    }
    copy.val=copieGrid(original.val,original.taille);

    return copy;
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
    assert(false && "getvoiture: id not found in plateau");
}

int getIndexVoiture(sgrid plateau,str id){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==id){return i;}
    }
    assert(false && "getIndexVoiture: id not found in plateau");
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
