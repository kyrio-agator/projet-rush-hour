#include "interface.h"


using grid=char**;
using ui=unsigned int;

void affiche(grid g,int s){
    std::cout<<std::endl;
    for(ui i=0;i<s;i++){
        for(ui j=0;j<s;j++){
            std::cout<<g[i][j];
        }
        std::cout<<std::endl;
    }
}