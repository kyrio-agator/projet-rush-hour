#pragma once

#include <array>
#include <iostream>
#include <string>

using str=std::string;
using grid=str**;
using arr2=std::array<int,2>;
const str emptychr="-";
const str borderchr="/";

using Move= std::array<str,2>;


struct path{
    arr2 dim;
    grid* g;
    int t;
};

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

void freePath(path &Gpath);
grid copieGrid(grid original, arr2 dim);
void afficherSgrid(sgrid& g);
voiture getvoiture(sgrid plateau,str id);
arr2* getCoordVoiture(voiture v);
int getIndexVoiture(sgrid plateau,str id);
bool victoire(sgrid plateau);
bool canMove(sgrid plateau,voiture v,char dir);
void addValuePath(path &Gpath,grid g);
bool equalGrid(grid g1,grid g2,arr2 dim);
bool doubleGridList(path l_grid,grid g);