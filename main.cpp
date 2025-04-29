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


    delete2Darray(plateau,s);
    return 0;
}