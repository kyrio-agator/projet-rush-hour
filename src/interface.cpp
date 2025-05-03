#include "interface.h"



void affiche(grid g,int s){
    std::cout<<std::endl;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            std::cout<<g[i][j];
        }
        std::cout<<std::endl;
    }
}

sf::Color charToColor(char c) {
    if(c=='X'){return sf::Color::Red;}
    if(c=='A'){return sf::Color::Blue;}
    if(c=='B'){return sf::Color::Green;}
    if(c=='C'){return sf::Color::Yellow;}
    else{return sf::Color::White;}
}

void interfaceSFML(sf::RenderWindow &window, grid plateau,int size,char vo) {
    float cellSize = window.getSize().x / size; // Scale cells to fit within 600x600

    window.clear(sf::Color::White); // Clear with background color


    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {

            sf::RectangleShape cell(sf::Vector2f(cellSize, cellSize));
            cell.setPosition(j * cellSize, i * cellSize);

            char currentChar = plateau[i][j];

            if (currentChar == emptychr) {cell.setFillColor(sf::Color(128, 128, 128));}
            else{
                cell.setFillColor(charToColor(currentChar));
                if(currentChar==vo){
                    cell.setOutlineColor(sf::Color::Black);
                    cell.setOutlineThickness(1.0f);
                    }
                }
            window.draw(cell);    
        }
    }
    window.display();
}