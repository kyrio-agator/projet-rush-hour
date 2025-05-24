#include "move.h"

bool exist(sgrid plateau,str c){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==c){return true;}
    }
    return false;
}

bool canMove(sgrid plateau,voiture v,char dir){
    arr2* v_coord=getCoordVoiture(v);

    bool r=false;
    if(v.ori=="horizontale"){
        if(dir=='d'){if(plateau.val[v_coord[v.taille-1][0]][v_coord[v.taille-1][1]+1]==emptychr){r=true;}}
        if(dir=='g'){if(plateau.val[v_coord[0]         [0]][v_coord[0]         [1]-1]==emptychr){r=true;}}
    }else{
        if(dir=='b'){if(plateau.val[v_coord[v.taille-1][0]+1][v_coord[v.taille-1][1]]==emptychr){r=true;}}
        if(dir=='h'){if(plateau.val[v_coord[0]         [0]-1][v_coord[0]         [1]]==emptychr){r=true;}}
    }     
    return r;
} 

void deplace(sgrid &plateau,str c,char dir){
    if(exist(plateau,c)){
        voiture v=getvoiture(plateau,c);
        int indexV=getIndexVoiture(plateau,c);
        arr2* v_coord=getCoordVoiture(v);

        if(v.ori=="horizontale"){
            if(dir=='d'){
                if(canMove(plateau,v,dir)){
                    //suprimé la voiture
                    for(int i=0;i<v.taille;i++){
                        plateau.val[v_coord[i][0]][v_coord[i][1]]=emptychr;
                    }
                    //la remetre une case vers la droite
                    for(int i=0;i<v.taille;i++){
                        plateau.val[v_coord[i][0]][v_coord[i][1]+1]=c;
                    }
                    plateau.v[indexV].coord={v_coord[0][0],v_coord[0][1]+1};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger a droite"<<std::endl;}
                
            }
            if(dir=='g'){
                if(canMove(plateau,v,dir)){
                    //suprimé la voiture
                    for(int i=0;i<v.taille;i++){
                        plateau.val[v_coord[i][0]][v_coord[i][1]]=emptychr;
                    }
                    //la remetre une case vers a gauche
                    for(int i=0;i<v.taille;i++){
                        plateau.val[v_coord[i][0]][v_coord[i][1]-1]=c;
                    }
                plateau.v[indexV].coord={v_coord[0][0],v_coord[0][1]-1};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger a gauche"<<std::endl;}
                
            }
        }
        else{
            if(dir=='b'){
                if(canMove(plateau,v,dir)){
                    //suprimé la voiture
                    for(int i=0;i<v.taille;i++){
                            plateau.val[v_coord[i][0]][v_coord[i][1]]=emptychr;
                        }
                    //la remetre une case vers le bas
                    for(int i=0;i<v.taille;i++){
                            plateau.val[v_coord[i][0]+1][v_coord[i][1]]=c;
                            
                        }
                    plateau.v[indexV].coord={v_coord[0][0]+1,v_coord[0][1]};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en bas"<<std::endl;}
                

            }
            if(dir=='h'){
                if(canMove(plateau,v,dir)){
                    //suprimé la voiture
                    for(int i=0;i<v.taille;i++){
                        plateau.val[v_coord[i][0]][v_coord[i][1]]=emptychr;
                    }
                    //la remetre une case vers le haut
                    for(int i=0;i<v.taille;i++){
                        plateau.val[v_coord[i][0]-1][v_coord[i][1]]=c;
                        
                    }
                    plateau.v[indexV].coord={v_coord[0][0]-1,v_coord[0][1]};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en haut"<<std::endl;}
                
            }
        }
    
        delete[] v_coord;
    }
    else{std::cout<<"la voiture n'existe pas"<<std::endl;}
}