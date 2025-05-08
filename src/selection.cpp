#include "selection.h"

str selectJson(str plt_dir) {
    str files[100];
    int count = 0;

    std::cout << "plateau disponible: "<<std::endl;

    for (const auto& entry : fs::directory_iterator(plt_dir)) {
        if (entry.path().extension() == ".json" && count < 100) {
            str fullPath = entry.path().string();
            std::ifstream file(fullPath);
            if (!file) continue;

            json j;

            file >> j;
            str nom = j["nom"];
            int niveau = j["niveau"];
            int largeur = j["largeur"];
            int hauteur = j["hauteur"];

            files[count] = entry.path().filename().string();
            std::cout << (count + 1) << ". " << nom
                      << " | Niveau: " << niveau
                      << " | " << largeur << "x" << hauteur << "\n";
            count++;
        }
    }

    if (count == 0) {
        std::cerr << "pas de json trouver."<<std::endl;
        return "";
    }

    std::cout << "jouer quelle plateau?: ";
    int choice;
    std::cin >> choice;

    if ((choice < 1)or(choice > count)) {
        std::cerr << "choix invalide."<<std::endl;
        return "";
    }

    str l = plt_dir + "/" + files[choice - 1];
    return l;
}