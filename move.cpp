#include "move.h"



char emptychr= '-';

bool exist(grid plateau,int s,char c){
    bool v=false;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(plateau[i][j]==c){v=true;}
        }
    }
    return v;
}

bool victoire(grid plateau,int s){
    bool v=false;
    for(int i=0;i<s;i++){
        if(plateau[i][s-1]=='X'){v=true;}
    }
    return v;
}

bool horizontal(grid plateau,int s,char c){
    bool v=false;
    for(int i=0;i<s;i++){
        for(int j=0;j<s-1;j++){
            if( (plateau[i][j]==c) && (plateau[i][j+1]==c) ){v=true;}
        }
    }
    return v;
}

int getsizecar(grid plateau,int s,char c){
    int t=0;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            if(plateau[i][j]==c){t++;}
        }
    }
    return t;
}

void deplace(grid &plateau,int s,char c,char dir){
    if(exist(plateau,s,c)){
        int taille_v=getsizecar(plateau,s,c);
        coord* v=new coord[taille_v];
        //obtenir les coord de la voiture
        int is=0; //index suivant de v
        for(int i=0;i<s;i++){
            for(int j=0;j<s;j++){
                if(plateau[i][j]==c){
                    v[is][0]=i;
                    v[is][1]=j;
                    is++;
                }
            }
        }
        if(horizontal(plateau,s,c)){
            //deplacement horizontal
            if(dir=='d'){
                //test si on peux deplacé a droite
                if(plateau[v[taille_v-1][0]][v[taille_v-1][1]+1]==emptychr){
                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers la droite
                    for(int i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]+1]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger a droite";}

            }
            if(dir=='g'){
                //test si on peux deplacé a gauche
                if(plateau[v[0][0]][v[0][1]-1]==emptychr){
                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers a gauche
                    for(int i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]-1]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger a gauche";}
            }
        }
        else{
            //deplacement vertical
            if(dir=='b'){
                //test si on peux deplacé a bas
                if(v[taille_v-1][0]+1<=s-1){
                if(plateau[v[taille_v-1][0]+1][v[taille_v-1][1]]==emptychr){
                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                            plateau[v[i][0]][v[i][1]]=emptychr;
                        }
                    //la remetre une case vers le bas
                    for(int i=0;i<taille_v;i++){
                            plateau[v[i][0]+1][v[i][1]]=c;
                        }
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en bas";}
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en bas";}
            }
            if(dir=='h'){
                //test si on peux deplacé en haut
                if(v[0][0]-1>=0){
                if(plateau[v[0][0]-1][v[0][1]]==emptychr){

                    //suprimé la voiture
                    for(int i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers le haut
                    for(int i=0;i<taille_v;i++){
                        plateau[v[i][0]-1][v[i][1]]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en haut";}
                }
                else{std::cout<<"la voiture "<<c<<" ne peux pas bouger en haut";}
            }
        }
    }
    else{std::cout<<"la voiture n'existe pas"<<std::endl;}
}