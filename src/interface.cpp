#include "interface.h"


void interfaceText(sgrid plateau){
    std::cout<<std::endl;
    std::cout << "Nom: " << plateau.nom <<std::endl;
    std::cout << "Taille: " << plateau.taille[0] << " x " << plateau.taille[1] << std::endl;
    std::cout << "Voiture de depart: " << plateau.v_dep << std::endl;
    std::cout << "Sortie: (" << plateau.fin[0] << ", " << plateau.fin[1] << ")"<<std::endl;
    std::cout << "Grille:"<<std::endl;

    for(int i=0;i<plateau.taille[0];i++){
        for(int j=0;j<plateau.taille[1];j++){
            std::cout<<plateau.val[i][j];
        }
        std::cout<<std::endl;
    }
}

sf::Color idToColor(str id) {
    
/*
if(rvb)
    extrait rvb
    int r,g,b;
    return rvb
else if( couleur = rouge){return sf::rouge}
else if( couleur = rouge){return sf::rouge}
else if( couleur = rouge){return sf::rouge}
else if( couleur = rouge){return sf::rouge}
else if( couleur = rouge){return sf::rouge}
else if( couleur = rouge){return sf::rouge}

else return white

*/
    if(id==emptychr){return sf::Color(128, 128, 128);}
    if(id=="X"){return sf::Color::Red;}
    if(id=="A"){return sf::Color::Blue;}
    if(id=="B"){return sf::Color::Green;}
    if(id=="C"){return sf::Color::Yellow;}
    if(id=="D"){return sf::Color::Magenta;}
    if(id=="E"){return sf::Color::Cyan;}
    if(id=="F"){return sf::Color(139,69,19);}
    if(id=="G"){return sf::Color(200,200,200);}
    else{return sf::Color::White;}
}

void interfaceSFML(sf::RenderWindow &window, sgrid plateau,str vo) {
    window.clear(sf::Color::White);

    float cellSizeX = window.getSize().x / plateau.taille[1];
    float cellSizeY = window.getSize().y / plateau.taille[0];

    for (int i = 0; i < plateau.taille[0]; ++i) {
        for (int j = 0; j < plateau.taille[1]; ++j) {

            sf::RectangleShape cell(sf::Vector2f(cellSizeX,cellSizeY));

            str currentCar = plateau.val[i][j];

            cell.setPosition(j * cellSizeX, i * cellSizeY);
            cell.setFillColor(idToColor(currentCar));

            if(currentCar==vo){
                cell.setOutlineColor(sf::Color::Black);
                cell.setOutlineThickness(-2);
            }
            window.draw(cell); 
            
            if(currentCar==plateau.v_dep){
                sf::CircleShape centerCircle;
                float radius = std::min(cellSizeX, cellSizeY) / 10;
                centerCircle.setRadius(radius);
                centerCircle.setFillColor(sf::Color(0,0,0,100));

                centerCircle.setPosition(j * cellSizeX + (cellSizeX / 2) - radius,
                                         i * cellSizeY + (cellSizeY / 2) - radius);
            
                window.draw(centerCircle);
            }
   
        }
    }

    sf::CircleShape circle;
    float rayon=std::min(cellSizeX, cellSizeY) / 10;
    circle.setRadius(rayon);
    circle.setFillColor(sf::Color::Black);

    float posX = plateau.fin[0] * cellSizeX + cellSizeX / 2 - rayon;
    float posY = plateau.fin[1] * cellSizeY + cellSizeY / 2 - rayon;
    circle.setPosition(posX, posY);

    window.draw(circle);

    window.display();
}