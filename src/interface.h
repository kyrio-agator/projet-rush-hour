#pragma once

#include "type.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>


bool ifDebut(voiture v,int i,int j);
bool ifFin(voiture v, int i, int j);
sf::Color tagToColor(str col);
void interfaceText(sgrid plateau);
void interfaceSFML(sf::RenderWindow &window,sgrid plateau,str vo);