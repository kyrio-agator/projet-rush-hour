#pragma once

#include "type.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

void interfaceText(sgrid plateau);
void interfaceSFML(sf::RenderWindow &window,sgrid plateau,str vo);
sf::Color charToColor(str c);