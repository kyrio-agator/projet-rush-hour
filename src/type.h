#pragma once

#include <array>
#include <iostream>
#include <string>

using str=std::string;
using grid=str**;
using coord=std::array<int,2>;
const str emptychr="-";
const str borderchr="/";

struct voiture{
    str id;
    str color;
    coord coord;
    int taille;
    str ori;
};

struct sgrid{
    str nom;
    int nb_voit;
    str v_dep;
    coord taille;
    coord fin;
    voiture* v;
    grid val;
};

void afficherSgrid(const sgrid& g);
voiture getvoiture(sgrid plateau,str id);
coord* getCoordVoiture(voiture v);
int getIndexVoiture(sgrid plateau,str id);
