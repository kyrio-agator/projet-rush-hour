#include "generate.h"
#include "interface.h"
#include "move.h"
#include "solve.h"
#include "type.h"
#include "selection.h"




int main(){
    str l=selectJson("../plateau");


    str reponceIA =" "; bool AIsolve=false;
    std::cout<<"utilise l'IA ?[y/n]: ";std::cin>>reponceIA;
    if(reponceIA=="y"){AIsolve=true;}

    if(l!=""){
        sgrid plateau=lirePlateauJson(l);
        str vo=plateau.v_dep;char di=' ';

        //AI
        if(AIsolve){
            path solveHistory;
            std::vector<grid> solveMemoire;
            solveHistory.push_back(copieSgrid(plateau));
            std::vector<Move> solveM;
            bool solveV=false;
            sf::RenderWindow window(sf::VideoMode(600, 600), "rush-hour");
            std::cout<<"calcule"<<std::endl;
            time_t debutTime=time(NULL);
            betterSolveMOV(window,solveHistory,solveMemoire,solveM,solveV); //calcule la solution et interface
            std::cout<<"solution de "<<solveM.size()<<" coup trouve en  "<<time(NULL)-debutTime<<" seconde"<<std::endl;


            for(unsigned int i=0;i<solveM.size();i++){
                std::cout<<"coup "<<i<<" "<<solveM[i][0]<<" "<<solveM[i][1]<<std::endl;
                interfaceSFML(window,plateau,solveM[i][0]);
                deplace(plateau,solveM[i][0],solveM[i][1][0]);  //solveM[i][1][0] car str=>char
                sf::sleep(sf::milliseconds(250));
            }

            deletesgrid(plateau); 
            window.close();
            
        
        

        }
        //player
        else{
            sf::RenderWindow window(sf::VideoMode(600, 600), "rush-hour");
            while (window.isOpen()){
                interfaceSFML(window,plateau,vo);

                sf::Event event;
                while(window.pollEvent(event)){
                    if(event.type==sf::Event::Closed){window.close();}

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

                if(di!=' '){
                    deplace(plateau,vo,di);
                    di=' ';
                }

                if(victoire(plateau)){
                    std::cout<<"gagne"<<std::endl;
                    window.close();}
                
                sf::sleep(sf::milliseconds(100));
                }
            deletesgrid(plateau);
        }
    }
}

