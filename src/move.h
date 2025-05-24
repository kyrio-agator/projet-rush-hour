#pragma once

#include "type.h"



bool exist(sgrid plateau,str c);
bool canMove(sgrid plateau,voiture v,char dir);
void deplace(sgrid &plateau,str c,char dir);