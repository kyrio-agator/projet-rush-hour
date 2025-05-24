#pragma once

#include "type.h"
#include "move.h"
#include "interface.h"
#include <ctime>


bool equalGrid(grid g1,grid g2,arr2 dim);
bool doubleGridList(std::vector<grid> l,arr2 t);

void betterSolveMOV(sf::RenderWindow &window,path& Gpath,std::vector<grid> &memory,std::vector<Move> &moveList,bool interface,bool &vic);
