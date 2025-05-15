#include "generate.h"
#include "interface.h"
#include "move.h"
#include "solve.h"
#include "type.h"
#include "selection.h"


int main(){
    std::srand(std::time(nullptr));

    str l=selectJson("../plateau");

        str reponceIA =" "; bool AIsolve=false; int frameTime=100; int AIstep=0; std::array<str,2> AIaction;
        std::cout<<"utilise l'IA ?[y/n]: ";std::cin>>reponceIA;

        if(reponceIA=="y"){
            AIsolve=true;
            frameTime=10;}

    if(l!=""){
        sf::RenderWindow window(sf::VideoMode(600, 600), "rush-hour");

        sgrid plateau=lirePlateauJson(l);
        str vo=plateau.v_dep;char di=' ';

        while (window.isOpen()) {
            interfaceSFML(window,plateau,vo);


            sf::Event event;
            while(window.pollEvent(event)){
                if(event.type==sf::Event::Closed){window.close();}

                if(!AIsolve){
                    if((event.type==sf::Event::MouseButtonPressed)and(event.mouseButton.button==sf::Mouse::Left)){
                        sf::Vector2i mousePos=sf::Mouse::getPosition(window);
                        int x=mousePos.x;  int y=mousePos.y;
                        int cellSizeX = window.getSize().x / plateau.taille[1];
                        int cellSizeY = window.getSize().y / plateau.taille[0];
                        if((plateau.val[y/cellSizeY][x/cellSizeX]!=emptychr)and(plateau.val[y/cellSizeY][x/cellSizeX]!=borderchr)){
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
            }

            if(AIsolve){
                AIaction=randomAI(plateau);
                vo=AIaction[0];
                di=AIaction[1][0];
                AIstep++;
            }

            if(di!=' '){
                deplace(plateau,vo,di);
                di=' ';
            }

            if(victoire(plateau)or(di=='v')){
                std::cout<<"gagne"<<std::endl;
                window.close();}
            
            
            sf::sleep(sf::milliseconds(frameTime));
        }
    delete2Darray(plateau);
    std::cout<<AIstep;
    }
}