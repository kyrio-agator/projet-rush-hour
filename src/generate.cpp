#include "generate.h"




grid initialisePlateau(int x, int y){
    //generate
    grid plateau = new std::string* [x];

    for(int i=0;i<x;i++){
        plateau[i]=new std::string[y];
    }

    //fill with empty
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            plateau[i][j]=emptychr;
        }
    }

    return plateau;
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
        j["hauteur"].get<int>()+2,
        j["largeur"].get<int>()+2
    };

    plateau.fin = {
        j["sortie"]["y"].get<int>(),
        j["sortie"]["x"].get<int>()
    };

    plateau.v=new voiture[plateau.nb_voit];
    plateau.val=initialisePlateau(plateau.taille[0],plateau.taille[1]);



    int i=0;
    for (json::iterator it=j["voitures"].begin();it!=j["voitures"].end();it++) {

        str id = (*it)["id"].get<str>();
        int x = (*it)["x"].get<int>()-1 ;
        int y = (*it)["y"].get<int>()-1 ;
        int taille = (*it)["taille"].get<int>();
        str color=(*it)["couleur"].get<str>();
        str ori = (*it)["orientation"].get<str>();

        plateau.v[i].color=color;
        plateau.v[i].coord={y+1,x+1};
        plateau.v[i].id=id;
        plateau.v[i].taille=taille;
        plateau.v[i].ori=ori;

        if (ori == "horizontale") {
            for (int dx = 0; dx < taille; ++dx) {
                plateau.val[y+1][x + dx+1] = id;
            }
        } 
        else{
            for (int dy = 0; dy < taille; ++dy) {
                plateau.val[y + dy+1][x+1] = id;
            }
        }
        i++;
    }



    // Placement de la voiture de départ
    str id =    j["voiture_dep"]["id"].get<str>();
    int x =     j["voiture_dep"]["x"].get<int>()-1 ;
    int y =     j["voiture_dep"]["y"].get<int>()-1 ;
    int taille =j["voiture_dep"]["taille"].get<int>();
    str color=  j["voiture_dep"]["couleur"].get<str>();
    str ori =   j["voiture_dep"]["orientation"].get<str>();

    plateau.v[i].color=color;
    plateau.v[i].coord={y+1,x+1};
    plateau.v[i].id=id;
    plateau.v[i].taille=taille;
    plateau.v[i].ori=ori;


    str ori0 = j["voiture_dep"]["orientation"].get<str>();
    if (ori0 == "horizontale") {
        for (int dx = 0; dx < taille; ++dx) {
            plateau.val[y+1][x + dx+1] = plateau.v_dep;
        }
    } else {
        for (int dy = 0; dy < taille; ++dy) {
            plateau.val[y + dy+1][x+1] = plateau.v_dep;
        }
    }

    //border

    for(int i=0;i<plateau.taille[0];i++){
        for(int j=0;j<plateau.taille[1];j++){
            if((i==0)||(i==plateau.taille[0]-1)||(j==0)||(j==plateau.taille[1]-1)){
                plateau.val[i][j]=borderchr;
            }
        }
    }

    if(plateau.val[plateau.fin[0]][plateau.fin[1]]==borderchr){
        plateau.val[plateau.fin[0]][plateau.fin[1]]=emptychr;
    }

    //afficherSgrid(plateau);
    return plateau;
}

