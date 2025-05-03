#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

using grid=char**;
const char emptychr='-';


void affiche(grid g,int s);
void interfaceSFML(sf::RenderWindow &window, grid plateau, int size,char vo);
sf::Color charToColor(char c);