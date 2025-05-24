#include "type.h"

void deletesgrid(sgrid plateau){
    for(int i=0;i<plateau.taille[0];i++){
        delete[] plateau.val[i];
    }
    delete[] plateau.val;
    delete[] plateau.v;
    
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

voiture getvoiture(sgrid &plateau,str id){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==id){return plateau.v[i];}
    }
    assert(false && "getvoiture: id not found in plateau");
}

int getIndexVoiture(sgrid &plateau,str id){
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

