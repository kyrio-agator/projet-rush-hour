#include "generate.h"
#include "gennewplateau.h"
#include "interface.h"
#include "move.h"
#include "solve.h"

using grid=char**;

int main(){
    sf::RenderWindow window(sf::VideoMode(600, 600), "Grid Viewer");

    std::string l="../plateau/plateau1.txt";
    int s=getsizeplateau(l);
    grid plateau=lirePlateau(l,s);
    char vo='X';char di=' ';

    while (window.isOpen()) {
        interfaceSFML(window, plateau, s,vo);

        sf::Event event;
        while(window.pollEvent(event)){
            if(event.type==sf::Event::Closed){window.close();}
            if((event.type==sf::Event::MouseButtonPressed)and(event.mouseButton.button==sf::Mouse::Left)){
                sf::Vector2i mousePos=sf::Mouse::getPosition(window);
                int x=mousePos.x;  int y=mousePos.y;
                int cellsize=window.getSize().x/s;
                vo=plateau[y/cellsize][x/cellsize];
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
            deplace(plateau,s,vo,di);
            di=' ';
        }

        if(victoire(plateau,s)or(di=='v')){
            std::cout<<"gagne";
            window.close();}
        sf::sleep(sf::milliseconds(200));
    }
    delete2Darray(plateau,s);
    
    /*
    std::cout<<"skill issue"<<std::endl;
    sf::RenderWindow window(sf::VideoMode(600, 600), "rush-hour");

    std::string l="../plateau/plateau1.txt";

    int s=getsizeplateau(l);
    grid plateau=lirePlateau(l,s);
    affiche(plateau,s);

    char vo=' ';char di=' ';
    //boucle de jeu
    while(di!='v'){
        std::cout<<"----------------"<<std::endl<<"symbole de voiture + b/h/d/g"<<std::endl;

        std::cin>>vo>>di;
        deplace(plateau,s,vo,di);
        changeTheGridSFML()
        if(victoire(plateau,s)){di='v';}
    }

    std::cout<<std::endl<<"gagne";

    delete2Darray(plateau,s);
*/
    return 0;
}