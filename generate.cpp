#include "generate.h"
#include <array>
#include <string>
#include <fstream>
#include <iostream>

using grid=int**;

grid initialisePlateau(int s){  //s = size
    //generate
    grid plateau = new int*[s];

    for(int i=0;i<s;i++){
        plateau[i]=new int[s];
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