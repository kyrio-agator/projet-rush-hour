#include "interface.h"
#include <iostream>
//#include <SFML/graphics.hpp>

using grid=int**;
using ui=unsigned int;

void affiche(grid g,int s){
    for(ui i=0;i<=s;i++){
        for(ui j=0;j<=s;j++){
            if(i==s){std::cout<<j+1;}
            else if(j==s){std::cout<<i+1;}
            else std::cout<<g[i][j];

        }
        std::cout<<std::endl;
    }
}