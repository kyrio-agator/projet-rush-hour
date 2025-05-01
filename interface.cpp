#include "interface.h"


using grid=char**;

void affiche(grid g,int s){
    std::cout<<std::endl;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            std::cout<<g[i][j];
        }
        std::cout<<std::endl;
    }
}