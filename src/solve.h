#pragma once

#include "type.h"
#include "move.h"
#include "interface.h"
#include <cstdlib>
#include <ctime>



std::array<str,2> randomAI(sgrid plateau);
char inverseDir(char d);
void betterSolve(sf::RenderWindow &window,sgrid &plateau,path& Gpath,int &AIstep);