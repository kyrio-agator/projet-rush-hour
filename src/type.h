#pragma once

#include <array>
#include <iostream>


using grid=char**;
using ui=unsigned int;
using coord=std::array<int,2>;
const char emptychr='-';

struct sgrid{
    std::string nom;
    int niv;
    char v_dep;
    coord taille;
    coord fin;
    grid val;
};