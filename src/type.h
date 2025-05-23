#pragma once

#include <array>
#include <iostream>
#include <string>
#include <iostream>
#include <cassert>
#include <vector>

using str=std::string;
using grid=str**;
using arr2=std::array<int,2>;
const str emptychr="-";
const str borderchr="/";
const unsigned int maxdepth=30; //max recurence de solve, limite la solution a 50 coup
const bool solveinterface=true;
using Move= std::array<str,2>;




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
void interfaceText(sgrid plateau);
void printVector(std::vector<Move> v);
grid copieGrid(grid original, arr2 dim);
sgrid copieSgrid(sgrid original);
void afficherSgrid(sgrid& g);
voiture getvoiture(sgrid &plateau,str id);
arr2* getCoordVoiture(voiture v);
int getIndexVoiture(sgrid &plateau,str id);
bool victoire(sgrid plateau);
bool canMove(sgrid plateau,voiture v,char dir);
