#pragma once

#include <array>
#include <iostream>
using grid=char**;
using ui=unsigned int;
using coord=std::array<int,2>;

bool exist(grid plateau,int s,char c);
bool victoire(grid plateau,int s);
bool horizontal(grid plateau,int s,char c);
int getsizecar(grid plateau,int s,char c);
void deplace(grid &plateau,int s,char c,char dir);