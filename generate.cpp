#include "generate.h"


using grid=char**;

grid initialisePlateau(int s){  //s = size
    //generate
    grid plateau = new char*[s];

    for(int i=0;i<s;i++){
        plateau[i]=new char[s];
    }

    //fill with ' '
    for(int i=0;i<s;i++){
        for(int j=0;i<s;i++){
            plateau[i][j]=' ';
        }
    }

    return plateau;
}

void delete2Darray(grid plateau,int s){
    for(int i=0;i<s;i++){
        delete[] plateau[i];
    }
    delete[] plateau;
}

grid lirePlateau(std::string l){
    std::ifstream fic;
    fic.open(l);
    if(fic.is_open()){
        
    }
    else{std::cout<<"fichier non ouvert";}

    return 0;
}