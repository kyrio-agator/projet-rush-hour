#include "solve.h"

std::array<str,2> randomAI(sgrid plateau){
    // Pick a random car
    int iVo = std::rand() % plateau.nb_voit;
    const voiture& car = plateau.v[iVo];

    // Determine valid directions based on orientation
    std::array<char, 2> ldir;
    if (car.ori == "horizontale") {
        ldir = {'g', 'd'};
    } else {
        ldir = {'h', 'b'};
    }

    // Pick random direction
    int iDi = std::rand() % 2;
    str direction(1, ldir[iDi]);  // Convert char to string

    return {car.id, direction};
}