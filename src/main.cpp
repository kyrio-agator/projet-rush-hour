#include "generate.h"
#include "interface.h"
#include "move.h"
#include "solve.h"
#include "type.h"
#include "selection.h"


int main(){

    str l=selectJson("../plateau");
    if(l!=""){

    sf::RenderWindow window(sf::VideoMode(600, 600), "rush-hour");


    sgrid plateau=lirePlateauJson(l);
    str vo=plateau.v_dep;
    char di=' ';

    while (window.isOpen()) {
        interfaceSFML(window,plateau,vo);
        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){window.close();}
            if((event.type==sf::Event::MouseButtonPressed)and(event.mouseButton.button==sf::Mouse::Left)){
                sf::Vector2i mousePos=sf::Mouse::getPosition(window);
                int x=mousePos.x;  int y=mousePos.y;
                int cellSizeX = window.getSize().x / plateau.taille[1];
                int cellSizeY = window.getSize().y / plateau.taille[0];
                if(plateau.val[y/cellSizeY][x/cellSizeX]!=emptychr){
                    vo=plateau.val[y/cellSizeY][x/cellSizeX];}
            }
            if(event.type==sf::Event::KeyPressed){
                switch(event.key.code){
                    case sf::Keyboard::Up:
                        di='h';
                        break;
                    case sf::Keyboard::Down:
                        di='b';
                        break;
                    case sf::Keyboard::Left:
                        di='g';
                        break;
                    case sf::Keyboard::Right:
                        di='d';
                        break;
                    default:
                        break;
                    }
            }
        }

        if(di!=' '){
            deplace(plateau,vo,di);
            di=' ';
        }
        if(victoire(plateau)or(di=='v')){
            std::cout<<"gagne";
            window.close();}
        sf::sleep(sf::milliseconds(200));
    }
    delete2Darray(plateau);
    }
}