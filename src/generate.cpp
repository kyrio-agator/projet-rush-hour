#include "generate.h"




grid initialisePlateau(int width, int height){  //s = size
    //generate
    grid plateau = new char*[height];

    for(int i=0;i<height;i++){
        plateau[i]=new char[width];
    }

    //fill with ' '
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

sgrid lirePlateauJson(std::string path) {
    std::ifstream ifs(path.c_str());
    sgrid plateau;

    if (!ifs) {
        std::cerr << "Erreur: impossible d'ouvrir le fichier JSON: " << path << std::endl;
        plateau.val = nullptr;
        return plateau;
    }

    json j;
    ifs >> j;

    // Lecture des champs de base
    plateau.nom = j["nom"].get<std::string>();
    plateau.niv = j["niveau"].get<int>();

    int largeur = j["largeur"].get<int>();
    int hauteur = j["hauteur"].get<int>();
    plateau.taille = {hauteur,largeur};

    plateau.fin = {
        j["sortie"]["x_sortie"].get<int>() -1,
        j["sortie"]["y_sortie"].get<int>() -1
    };

    plateau.val = initialisePlateau(largeur, hauteur);

    // Placement des voitures classiques
    for (json::iterator it = j["voitures"].begin(); it != j["voitures"].end(); ++it) {

        char id = (*it)["id"].get<std::string>()[0];
        int x = (*it)["x"].get<int>() - 1;
        int y = (*it)["y"].get<int>() - 1;
        int taille = (*it)["taille"].get<int>();

        std::string ori = (*it)["orientation"].get<std::string>();
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
    }

    // Placement de la voiture de départ
    json vd = j["voiture_dep"];
    plateau.v_dep = vd["id"].get<std::string>()[0];
    int x0 = vd["x_dep"].get<int>() - 1;
    int y0 = vd["y_dep"].get<int>() - 1;
    int t0 = vd["taille_dep"].get<int>();

    std::string ori0 = vd["orientation_dep"].get<std::string>();
    if (ori0 == "horizontale") {
        for (int dx = 0; dx < t0; ++dx) {
            plateau.val[y0][x0 + dx] = plateau.v_dep;
        }
    } else {
        for (int dy = 0; dy < t0; ++dy) {
            plateau.val[y0 + dy][x0] = plateau.v_dep;
        }
    }

    return plateau;
}