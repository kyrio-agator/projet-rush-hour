#include "solve.h"


bool equalGrid(grid g1,grid g2,arr2 dim){
    for(int i=0;i<dim[0];i++){
        for(int j=0;j<dim[1];j++){
            if(g1[i][j]!=g2[i][j]){return false;}
        }
    }
    return true;
}

bool doubleGridList(std::vector<grid> l,arr2 t){   //cherche si le dernier element est deja dans la list
    if(l.size()==1){return false;}
    grid last=l.back();
    for (unsigned int i = 0; i < l.size()-1; i++) {
        if (equalGrid(l.at(i), last,t)) {
            return true;
        }
    }

    return false;
}



void betterSolveMOV(sf::RenderWindow &window,path& Gpath,std::vector<grid> &memory,std::vector<Move> &moveList,bool &vic){
    if(vic){return;}
    
    sf::Event event;
    while(window.pollEvent(event)){if(event.type==sf::Event::Closed){window.close();assert(false);}}
                
    voiture* liste_voitures=new voiture[Gpath.back().nb_voit]; //recupe toute les voiture, lis la liste a l'envers pour avoir V_dep en premier, et donc le bouger en premier
    for(int i=Gpath.back().nb_voit-1;i>=0;i--){
        liste_voitures[i]=Gpath.back().v[i];
    }

    for(int id_v=0;id_v<Gpath.back().nb_voit;id_v++){
        voiture current_v=liste_voitures[id_v];
        std::array<char,2> dir_pos = {'h','b'};
        if(current_v.ori=="horizontale"){dir_pos = {'d','g'};}
        for(char dir : dir_pos){ 
            if(canMove(Gpath.back(),current_v,dir)){
                sgrid tempsgrid=copieSgrid(Gpath.back()); 

                deplace(tempsgrid,current_v.id,dir);
                if(solveinterface){interfaceSFML(window,tempsgrid,current_v.id);}
                
                
                moveList.push_back({current_v.id,str(1,dir)});
                Gpath.push_back(copieSgrid(tempsgrid));
                memory.push_back(copieGrid(tempsgrid.val,tempsgrid.taille));

                if(victoire(Gpath.back())){vic=true;return;}
                
                deletesgrid(tempsgrid);

                //si le coup a deja été fais ou si on est trop profond dans l'arbre, annulé le coup et passé a une autre "branche" des coup possible
                if((doubleGridList(memory,Gpath[0].taille))or(moveList.size()>=maxdepth)){
                    //std::cout<<"double"<<std::endl;
                    moveList.pop_back();
                    Gpath.pop_back();
                    memory.pop_back();
                }
                else{
                    //std::cout<<"descend"<<std::endl;
                    betterSolveMOV(window,Gpath,memory,moveList,vic);
                    //std::cout<<"remonte"<<std::endl;
                    if(vic){return;}
                    moveList.pop_back(); 
                    Gpath.pop_back();
                    
                    
                }
            }     
        }
    }


    delete[] liste_voitures;
    //std::cout<<"deadend"<<std::endl;
    return;
}


