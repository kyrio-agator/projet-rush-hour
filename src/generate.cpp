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
        for(int j=0;j<s;j++){
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

int getsizeplateau(std::string l){
    std::ifstream fic;
    fic.open(l);
    if(fic.is_open()){
        std::string line;
        std::getline(fic, line);
        return line.length();
    }   
    return 0;
}

grid lirePlateau(std::string l,int s){
    std::ifstream fic;
    fic.open(l);
    if(fic.is_open()){

        std::string line;
        grid plateau=initialisePlateau(s);
        int i=0;

        while (fic.good()){
            std::getline(fic, line);
            for(int j=0;j<s;j++){
                plateau[i][j]=line[j];
            }
            i++;
        }
        return plateau;
    }
    else{std::cout<<"fichier non ouvert";}
return 0;
}

