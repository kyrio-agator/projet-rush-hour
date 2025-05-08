#pragma once

#include "type.h"



bool exist(sgrid plateau,str c);
bool victoire(sgrid plateau);
bool horizontal(sgrid plateau,str c);
int getsizecar(sgrid plateau,str c);
void deplace(sgrid &plateau,str c,char dir);