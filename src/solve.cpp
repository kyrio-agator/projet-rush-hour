#include "solve.h"


char inverseDir(char d) {
    switch(d) {
        case 'h': return 'b';
        case 'b': return 'h';
        case 'g': return 'd';
        case 'd': return 'g';
    }
    return d;
}

bool equalGrid(grid g1,grid g2,arr2 dim){
    for(int i=0;i<dim[0];i++){
        for(int j=0;j<dim[1];j++){
            if(g1[i][j]!=g2[i][j]){return false;}
        }
    }
    return true;
}

bool doubleGridList(path l){   //cherche si le dernier element est deja dans la list
    if(l.size()==1){return false;}
    sgrid last=l.back();
    for (unsigned int i = 0; i < l.size()-1; i++) {
        if (equalGrid(l.at(i).val, last.val,l.at(i).taille)) {
            return true;
        }
    }

    return false;
}




void betterSolveMOV(sf::RenderWindow &window,path& Gpath,std::vector<Move> &moveList){
    std::cout<<Gpath.size()<<std::endl;
    voiture* liste_voitures=new voiture[Gpath.back().nb_voit]; //recupe toute les voiture
    for(int i=0;i<Gpath.back().nb_voit;i++){
        liste_voitures[i]=Gpath.back().v[i];
    }
    if(victoire(Gpath.back())){return;}
    sf::Event event;
    while(window.pollEvent(event)){
        if(event.type==sf::Event::Closed){window.close();return;}}
                
    while(doubleGridList(Gpath)){
        Gpath.pop_back();
        moveList.pop_back();
    }
    for(int id_v=0;id_v<Gpath.back().nb_voit;id_v++){
        voiture current_v=liste_voitures[id_v];
        for(char dir : {'d','g','h','b'}){     
            if(canMove(Gpath.back(),current_v,dir)){
                sgrid tempsgrid=copieSgrid(Gpath.back());
                deplace(tempsgrid,current_v.id,dir);
                interfaceSFML(window,Gpath.back(),current_v.id);
                moveList.push_back({current_v.id,str(1, dir)});
                Gpath.push_back(tempsgrid);

                
                //si le coup a deja été fais, annulé le coup et passé a une autre "branche" des coup possible
                if(doubleGridList(Gpath)){
                    Gpath.pop_back();
                    moveList.pop_back();
                }
                else{
                    betterSolveMOV(window,Gpath,moveList);
                }
            }     
        }
    }
    Gpath.pop_back();
    moveList.pop_back();
    return;
}


