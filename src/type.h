#pragma once

#include <array>
#include <iostream>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <ctime>

using str=std::string;
using grid=str**;
using arr2=std::array<int,2>;
using Move= std::array<str,2>;

const str emptychr="-";   //charactere pour les espace vide 
const str borderchr="/";  //charactere pour les bordure
const unsigned int maxdepth=80; //max recurence de solve, limite la solution a 100 coup
const bool solveinterface=true;//interface pendant que sa solve


struct voiture{
    str id;
    str color;
    arr2 coord;
    int taille;
    str ori;
};

struct sgrid{
    str nom;
    int nb_voit;
    str v_dep;
    arr2 taille;
    arr2 fin;
    voiture* v;
    grid val;
};

using path=std::vector<sgrid>;

void deletesgrid(sgrid grid);
sgrid copieSgrid(sgrid original);
grid copieGrid(grid original, arr2 dim);
voiture getvoiture(sgrid &plateau,str id);
arr2* getCoordVoiture(voiture v);
int getIndexVoiture(sgrid &plateau,str id);
bool victoire(sgrid plateau);
