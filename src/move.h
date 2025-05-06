#pragma once

#include "type.h"



bool exist(sgrid plateau,char c);
bool victoire(sgrid plateau);
bool horizontal(sgrid plateau,char c);
int getsizecar(sgrid plateau,char c);
void deplace(sgrid &plateau,char c,char dir);