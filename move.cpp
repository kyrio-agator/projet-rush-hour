#include "move.h"


void printlist(coord* l,int s){
    for(int i=0;i<s;i++){
        std::cout<<l[i][0]<<' '<<l[i][1]<<std::endl;
    }
}

char emptychr= '-';

bool exist(grid plateau,int s,char c){
    bool v=false;
    for(ui i=0;i<s;i++){
        for(ui j=0;j<s;j++){
            if(plateau[i][j]==c){v=true;}
        }
    }
    return v;
}

bool victoire(grid plateau,int s){
    bool v=false;
    for(ui i=0;i<s;i++){
        if(plateau[i][s-1]=='X'){v=true;}
    }
    return v;
}

bool horizontal(grid plateau,int s,char c){
    bool v=false;
    for(ui i=0;i<s;i++){
        for(ui j=0;j<s-1;j++){
            if( (plateau[i][j]==c) && (plateau[i][j+1]==c) ){v=true;}
        }
    }
    return v;
}

int getsizecar(grid plateau,int s,char c){
    int t=0;
    for(ui i=0;i<s;i++){
        for(ui j=0;j<s;j++){
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
        ui is=0; //index suivant de v
        for(ui i=0;i<s;i++){
            for(ui j=0;j<s;j++){
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
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers la droite
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]+1]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" peux pas bouger a "<<dir;}

            }
            if(dir=='g'){
                //test si on peux deplacé a gauche
                if(plateau[v[0][0]][v[0][1]-1]==emptychr){
                    //suprimé la voiture
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers a gauche
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]-1]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" peux pas bouger a "<<dir;}
            }
        }
        else{
            //deplacement vertical
            if(dir=='b'){
                //test si on peux deplacé a bas
                if(plateau[v[taille_v-1][0]+1][v[taille_v-1][1]]==emptychr){
                    //suprimé la voiture
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers le bas
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]+1][v[i][1]]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" peux pas bouger a "<<dir;}

            }
            if(dir=='h'){
                //test si on peux deplacé en haut
                if(plateau[v[0][0]-1][v[0][1]]==emptychr){
                    //suprimé la voiture
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]][v[i][1]]=emptychr;
                    }
                    //la remetre une case vers le haut
                    for(ui i=0;i<taille_v;i++){
                        plateau[v[i][0]-1][v[i][1]]=c;
                    }
                }
                else{std::cout<<"la voiture "<<c<<" peux pas bouger a "<<dir;}
            }
        }
    }
    else{std::cout<<"la voiture n'existe pas"<<std::endl;}
}