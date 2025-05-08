#pragma once

#include <array>
#include <iostream>
#include <string>

using str=std::string;
using grid=str**;
using ui=unsigned int;
using coord=std::array<int,2>;
const str emptychr="-";

struct sgrid{
    str nom;
    int niv;
    str v_dep;
    coord taille;
    coord fin;
    grid val;
};