#pragma once

#include "type.h"
#include "move.h"
#include "interface.h"
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


char inverseDir(char d);
bool equalGrid(grid g1,grid g2,arr2 dim);
bool doubleGridList(path l);

void betterSolveMOV(sf::RenderWindow &window,path& Gpath,std::vector<Move> &moveList,bool interface,bool &vic);
