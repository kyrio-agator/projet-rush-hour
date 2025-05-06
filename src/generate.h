#pragma once

#include "type.h"

#include <string>
#include <fstream>
#include "../include/json.hpp"
using json = nlohmann::json;

grid initialisePlateau(int width, int height);
void delete2Darray(sgrid grid);
sgrid lirePlateauJson(std::string l);
