#include "generate.h"
#include "gennewplateau.h"
#include "interface.h"
#include "move.h"
#include "solve.h"

using grid=char**;

int main(){
    std::cout<<"skill issue"<<std::endl;

    //interfaceSFML();

    std::string l="./plateau/plateau1.txt";

    int s=getsizeplateau(l);
    grid plateau=lirePlateau(l,s);
    affiche(plateau,s);

    char vo=' ';char di=' ';
    //boucle de jeu
    while(di!='v'){
        std::cout<<"----------------"<<std::endl<<"symbole de voiture + b/h/d/g"<<std::endl;

        std::cin>>vo>>di;
        deplace(plateau,s,vo,di);
        affiche(plateau,s);
        if(victoire(plateau,s)){di='v';}
    }

    std::cout<<std::endl<<"gagne";

    delete2Darray(plateau,s);

    return 0;
}