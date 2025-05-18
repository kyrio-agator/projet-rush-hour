#include "solve.h"

Move randomAI(sgrid plateau){
    // Pick a random car
    int iVo = std::rand() % plateau.nb_voit;
    const voiture& car = plateau.v[iVo];

    std::array<char, 2> ldir;
    if (car.ori == "horizontale") {
        ldir = {'g', 'd'};
    } else {
        ldir = {'h', 'b'};
    }

    int iDi = std::rand() % 2;
    str direction(1, ldir[iDi]);

    return {car.id, direction};
}

char inverseDir(char d) {
    switch(d) {
        case 'h': return 'b';
        case 'b': return 'h';
        case 'g': return 'd';
        case 'd': return 'g';
    }
    return d;
}

void betterSolve(sf::RenderWindow &window,sgrid &plateau,path& Gpath,int &AIstep){
    voiture* liste_voitures=new voiture[plateau.nb_voit];
    for(int i=0;i<plateau.nb_voit;i++){
        liste_voitures[i]=plateau.v[i];
    }
    
    for(int id_v=0;id_v<plateau.nb_voit;id_v++){
        voiture current_v=liste_voitures[id_v];
        for(char dir : {'h','b','g','d'}){
            if(victoire(plateau)){return;}
            if(canMove(plateau,current_v,dir)){
                std::cout<<current_v.id<<" "<<dir<<std::endl;
                deplace(plateau,current_v.id,dir);
                AIstep++;
                Gpath.g[Gpath.t]=copieGrid(plateau.val,plateau.taille);
                Gpath.t++;

                //interfaceSFML(window,plateau,current_v.id);
                interfaceText(plateau);
                sf::sleep(sf::milliseconds(100));
                
                //si le coup a deja été fais, annulé le coup et passé a une autre "branche" des coup possible
                if(doubleGridList(Gpath,plateau.val)){
                    std::cout<<"annulation du coup "<<current_v.id<<" "<<dir<<std::endl;
                    deplace(plateau,current_v.id,inverseDir(dir));
                    Gpath.t--;
                    AIstep++;

                    //interfaceSFML(window,plateau,current_v.id);
                    interfaceText(plateau);
                    sf::sleep(sf::milliseconds(100));
                }
                else{
                    betterSolve(window,plateau,Gpath,AIstep);
                }
            }     
        }
    }
    return;
}

