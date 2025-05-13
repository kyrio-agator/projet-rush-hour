#include "generate.h"




grid initialisePlateau(int width, int height){
    //generate
    grid plateau = new std::string* [height];

    for(int i=0;i<height;i++){
        plateau[i]=new std::string[width];
    }

    //fill with empty
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            plateau[i][j]=emptychr;
        }
    }

    return plateau;
}

void delete2Darray(sgrid plateau){
    for(int i=0;i<plateau.taille[0];i++){
        delete[] plateau.val[i];
    }
    delete[] plateau.val;
}

sgrid lirePlateauJson(str l) {
    std::ifstream ifs(l.c_str());
    sgrid plateau;

    if (!ifs) {
        std::cerr << "Erreur: impossible d'ouvrir le fichier JSON: " << l << std::endl;
        plateau.val = nullptr;
        return plateau;
    }
    json j;
    ifs >> j;

    // Lecture des champs de base
    plateau.nom = j["nom"].get<str>();
    plateau.nb_voit=j["voitures"].size()+1;
    plateau.v_dep=j["voiture_dep"]["id"].get<str>();

    plateau.taille = {
        j["hauteur"].get<int>(),
        j["largeur"].get<int>()
    };

    plateau.fin = {
        j["sortie"]["x"].get<int>() -1,
        j["sortie"]["y"].get<int>() -1
    };

    plateau.v=new voiture[plateau.nb_voit];
    plateau.val=initialisePlateau(plateau.taille[0],plateau.taille[1]);



    ui i=0;
    for (json::iterator it=j["voitures"].begin();it!=j["voitures"].end();it++) {

        str id = (*it)["id"].get<str>();
        int x = (*it)["x"].get<int>() - 1;
        int y = (*it)["y"].get<int>() - 1;
        int taille = (*it)["taille"].get<int>();
        str color=(*it)["couleur"].get<str>();
        str ori = (*it)["orientation"].get<str>();

        plateau.v[i].color=color;
        plateau.v[i].coord={x,y};
        plateau.v[i].id=id;
        plateau.v[i].taille=taille;
        plateau.v[i].ori=ori;

        if (ori == "horizontale") {
            for (int dx = 0; dx < taille; ++dx) {
                plateau.val[y][x + dx] = id;
            }
        } 
        else{
            for (int dy = 0; dy < taille; ++dy) {
                plateau.val[y + dy][x] = id;
            }
        }
        i++;
    }



    // Placement de la voiture de départ
    str id =    j["voiture_dep"]["id"].get<str>();
    int x =     j["voiture_dep"]["x"].get<int>() - 1;
    int y =     j["voiture_dep"]["y"].get<int>() - 1;
    int taille =j["voiture_dep"]["taille"].get<int>();
    str color=  j["voiture_dep"]["couleur"].get<str>();
    str ori =   j["voiture_dep"]["orientation"].get<str>();

    plateau.v[i].color=color;
    plateau.v[i].coord={x,y};
    plateau.v[i].id=id;
    plateau.v[i].taille=taille;
    plateau.v[i].ori=ori;


    str ori0 = j["voiture_dep"]["orientation"].get<str>();
    if (ori0 == "horizontale") {
        for (int dx = 0; dx < taille; ++dx) {
            plateau.val[y][x + dx] = plateau.v_dep;
        }
    } else {
        for (int dy = 0; dy < taille; ++dy) {
            plateau.val[y + dy][x] = plateau.v_dep;
        }
    }

    return plateau;
}

