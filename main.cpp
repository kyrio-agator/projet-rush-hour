#include "generate.h"
#include "gennewplateau.h"
#include "interface.h"
#include "move.h"
#include "solve.h"

using grid=char**;

int main(){
    std::string l="../plateau/plateau1.txt";
    
    int s=getsizeplateau(l);
    grid plateau=lirePlateau(l,s);
    affiche(plateau,s);

    char voit=' ';char di=' ';
    while(di!='v'){
        std::cout<<"#############"<<std::endl<<"v+d? :";

        std::cin>>voit>>di;
        deplace(plateau,s,voit,di);
        affiche(plateau,s);
        if(victoire(plateau,s)){di='v';}
    }

    std::cout<<std::endl<<"gagne";

    //delete2Darray(plateau,s);
    return 0;
}