#include "generate.h"
#include "gennewplateau.h"
#include "interface.h"
#include "move.h"
#include "solve.h"

using grid=char**;

int main(){
    grid plateau=initialisePlateau(6);
    affiche(plateau,6);
    return 0;
}