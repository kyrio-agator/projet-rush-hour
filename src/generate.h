#pragma once

#include "type.h"

#include <fstream>
#include "../include/json.hpp"
using json = nlohmann::json;

grid initialisePlateau(int width, int height);
sgrid lirePlateauJson(std::string l);
