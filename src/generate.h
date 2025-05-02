#pragma once

#include <array>
#include <string>
#include <fstream>
#include <iostream>

char** initialisePlateau(int s);
void delete2Darray(char** grid,int s);
int getsizeplateau(std::string l);
char** lirePlateau(std::string l,int s);
