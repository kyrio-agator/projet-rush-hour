#include "move.h"

bool exist(sgrid plateau,str c){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==c){return true;}
    }
    return false;
}

bool victoire(sgrid plateau){
    int x=plateau.fin[0];int y=plateau.fin[1];
    return plateau.val[x][y]==plateau.v_dep;
}

bool horizontal(sgrid plateau,str c){
    for(int i=0;i<plateau.nb_voit;i++){
        if((plateau.v[i].id==c)&&(plateau.v[i].ori=="horizontale")){return true;}
    }
    return false;
}

int getsizecar(sgrid plateau,str c){
    for(int i=0;i<plateau.nb_voit;i++){
        if(plateau.v[i].id==c){return plateau.v[i].taille;}
    }
    return 0;
}

void deplace(sgrid &plateau,str c,char dir){
    if(exist(plateau,c)){
        int indexV=getIndexVoiture(plateau,c);
        int taille_v=getsizecar(plateau,c);
        coord* v=new coord[taille_v];
        //obtenir les coord de la voiture
        int is=0; //index suivant de v
        for(int i=1;i<plateau.taille[0];i++){
            for(int j=1;j<plateau.taille[1];j++){
                if(plateau.val[i][j]==c){
                    v[is][0]=i;
                    v[is][1]=j;
                    is++;
                }
            }
        }
        
        if(horizontal(plateau,c)){
            //deplacement horizontal
            if(dir=='d'){
                //test si on peux deplacé a droite
                if(plateau.val[v[taille_v-1][0]][v[taille_v-1][1]+1]==emptychr){
                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                        plateau.val[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers la droite
                    for(int i=0;i<taille_v;i++){
                        plateau.val[v[i][0]][v[i][1]+1]=c;
                    }
                    plateau.v[indexV].coord={v[0][0],v[0][1]+1};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger a droite"<<std::endl;}

            }
            if(dir=='g'){
                //test si on peux deplacé a gauche
                if(plateau.val[v[0][0]][v[0][1]-1]==emptychr){
                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                        plateau.val[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers a gauche
                    for(int i=0;i<taille_v;i++){
                        plateau.val[v[i][0]][v[i][1]-1]=c;
                    }
                plateau.v[indexV].coord={v[0][0],v[0][1]-1};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger a gauche"<<std::endl;}
            }
        }
        else{
            //deplacement vertical
            if(dir=='b'){
                //test si on peux deplacé a bas
                if(v[taille_v-1][0]+1<=plateau.taille[0]-1){
                if(plateau.val[v[taille_v-1][0]+1][v[taille_v-1][1]]==emptychr){
                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                            plateau.val[v[i][0]][v[i][1]]=emptychr;
                        }
                    //la remetre une case vers le bas
                    for(int i=0;i<taille_v;i++){
                            plateau.val[v[i][0]+1][v[i][1]]=c;
                            
                        }
                    plateau.v[indexV].coord={v[0][0]+1,v[0][1]};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en bas"<<std::endl;}
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en bas"<<std::endl;}
            }
            if(dir=='h'){
                //test si on peux deplacé en haut
                if(v[0][0]-1>=0){
                if(plateau.val[v[0][0]-1][v[0][1]]==emptychr){

                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                        plateau.val[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers le haut
                    for(int i=0;i<taille_v;i++){
                        plateau.val[v[i][0]-1][v[i][1]]=c;
                        
                    }
                    plateau.v[indexV].coord={v[0][0]-1,v[0][1]};
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en haut"<<std::endl;}
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en haut"<<std::endl;}
            }
        }
    }
    else{std::cout<<"la voiture n'existe pas"<<std::endl;}
}