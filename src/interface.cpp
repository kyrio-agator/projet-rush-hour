#include "interface.h"


void interfaceText(sgrid plateau){
    std::cout<<std::endl;
    std::cout << "Nom: " << plateau.nom << "\n";
    std::cout << "niveau: " << plateau.niv << "\n";
    std::cout << "Taille: " << plateau.taille[0] << " x " << plateau.taille[1] << "\n";
    std::cout << "Voiture de depart: " << plateau.v_dep << "\n";
    std::cout << "Sortie: (" << plateau.fin[0] << ", " << plateau.fin[1] << ")\n";
    std::cout << "Grille:\n";

    for(int i=0;i<plateau.taille[0];i++){
        for(int j=0;j<plateau.taille[1];j++){
            std::cout<<plateau.val[i][j];
        }
        std::cout<<std::endl;
    }
}

sf::Color idToColor(str c) {
    if(c=="X"){return sf::Color::Red;}
    if(c=="A"){return sf::Color::Blue;}
    if(c=="B"){return sf::Color::Green;}
    if(c=="C"){return sf::Color::Yellow;}
    if(c=="D"){return sf::Color::Magenta;}
    if(c=="E"){return sf::Color::Cyan;}
    if(c=="F"){return sf::Color(139,69,19);}
    if(c=="G"){return sf::Color(200,200,200);}
    else{return sf::Color::White;}
}

void interfaceSFML(sf::RenderWindow &window, sgrid plateau,str vo) {
    float cellSizeX = window.getSize().x / plateau.taille[1];
    float cellSizeY = window.getSize().y / plateau.taille[0];

    window.clear(sf::Color::White); // Clear with background color


    for (int i = 0; i < plateau.taille[0]; ++i) {
        for (int j = 0; j < plateau.taille[1]; ++j) {

            sf::RectangleShape cell(sf::Vector2f(cellSizeX,cellSizeY));
            cell.setPosition(j * cellSizeX, i * cellSizeY);

            str currentCar = plateau.val[i][j];

            if (currentCar == emptychr) {cell.setFillColor(sf::Color(128, 128, 128));}
            else{
                cell.setFillColor(idToColor(currentCar));
                if(currentCar==vo){
                    cell.setOutlineColor(sf::Color::Black);
                    cell.setOutlineThickness(1.0f);
                    }
                }
            window.draw(cell);    
        }
    }
    sf::CircleShape circle;
    float radius = std::min(cellSizeX, cellSizeY) / 6.0f;
    circle.setRadius(radius);
    circle.setFillColor(sf::Color::Black);

    // Position the circle at center of the (cx, cy) cell
    float posX = plateau.fin[0] * cellSizeX + cellSizeX / 2.0f - radius;
    float posY = plateau.fin[1] * cellSizeY + cellSizeY / 2.0f - radius;
    circle.setPosition(posX, posY);

    window.draw(circle);


    window.display();
}