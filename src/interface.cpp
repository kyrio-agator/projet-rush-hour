#include "interface.h"

sf::Color tagToColor(str col) {
    if((col[0]=='r')and(col[1]=='v')and(col[2]=='b')){
        str R,G,B;int j=0;
        for(unsigned int i=4;i<col.length()-1;i++){
            if(col[i]==','){j++;}
            
            else if(j==0){R+=col[i];}
            else if(j==1){G+=col[i];}
            else if(j==2){B+=col[i];}
        }
        return sf::Color(std::stoi(R),std::stoi(G),std::stoi(B));
    }
    
    if     (col=="rouge")  {return sf::Color(255,0,  0  );}
    else if(col=="vert")   {return sf::Color(0  ,255,0  );}
    else if(col=="bleu")   {return sf::Color(0  ,0  ,255);}
    else if(col=="cyan")   {return sf::Color(0  ,255,255);}
    else if(col=="magenta"){return sf::Color(255,0  ,255);}
    else if(col=="jaune")  {return sf::Color(255,255,0  );}
    else if(col=="orange") {return sf::Color(255,128,0  );}
    else if(col=="rose")   {return sf::Color(255,105,180);}
    else if(col=="violet") {return sf::Color(240,130,240);}
    else if(col=="maron")  {return sf::Color(160,120,100);}
    
    return sf::Color::White;
}

bool ifDebut(voiture v,int i,int j){
    if((v.coord[0]==i)and(v.coord[1]==j)){return true;}
    return false;
}

bool ifFin(voiture v, int i, int j) {
    if (v.ori == "horizontale") {
        return (v.coord[0] == i) && (v.coord[1] + v.taille - 1 == j);
    } else if (v.ori == "verticale") {
        return (v.coord[0] + v.taille - 1 == i) && (v.coord[1] == j);
    }
    return false;
}

void interfaceText(sgrid plateau){
    for(int i=0;i<plateau.taille[0];i++){
        for(int j=0;j<plateau.taille[1];j++){
            std::cout<<plateau.val[i][j];
        }
        std::cout<<std::endl;
    }
}

void interfaceSFML(sf::RenderWindow &window, sgrid plateau,str vo) {
    window.clear(sf::Color::White);

    //load les texture
    
    static sf::Texture tex_in, tex_out,tex_voit1,tex_voit2,tex_voit3;
    static bool texturesLoaded = false;
    if (!texturesLoaded) {
        tex_in.loadFromFile("../assets/fin_in.png");
        tex_out.loadFromFile("../assets/fin_out.png");
        tex_voit1.loadFromFile("../assets/voit1.png");
        tex_voit2.loadFromFile("../assets/voit2.png");
        tex_voit3.loadFromFile("../assets/voit3.png");
        texturesLoaded = true;
    }
    float cellSizeX = window.getSize().x / plateau.taille[1];
    float cellSizeY = window.getSize().y / plateau.taille[0];




    //grid   
    for (int i = 0; i < plateau.taille[0]; ++i) {
        for (int j = 0; j < plateau.taille[1]; ++j) {
            
            str currentId = plateau.val[i][j];

            sf::RectangleShape cell(sf::Vector2f(cellSizeX, cellSizeY));
            cell.setPosition(j * cellSizeX, i * cellSizeY);
            if(currentId==borderchr){cell.setFillColor(sf::Color(50,50,50));}
            else{cell.setFillColor(sf::Color(128,128,128));}
            window.draw(cell);


            // Si c'est une voiture, dessiner une texture par-dessus
            if (currentId != emptychr and currentId != borderchr) {
                voiture currentVoit = getvoiture(plateau, currentId);

                sf::Texture tex = tex_voit2;
                if (ifDebut(currentVoit, i, j)) {
                    tex = tex_voit1;
                } else if (ifFin(currentVoit, i, j)) {
                    tex = tex_voit3;
                }

                sf::Sprite sprite;
                sprite.setTexture(tex);
                sprite.setColor(tagToColor(currentVoit.color));
                
                float scaleX = cellSizeX / tex.getSize().x;
                float scaleY = cellSizeY / tex.getSize().y;

                // Par défaut, on applique l'échelle et la position
                sprite.setScale(scaleX, scaleY);
                sprite.setPosition(j * cellSizeX, i * cellSizeY);

                // Si verticale, on pivote et ajuste la position et scale
                if (currentVoit.ori == "verticale") {
                    sprite.setOrigin(tex.getSize().x / 2.f, tex.getSize().y / 2.f);
                    sprite.setPosition(j * cellSizeX + cellSizeX / 2, i * cellSizeY + cellSizeY / 2);
                    sprite.setRotation(90);
                    sprite.setScale(scaleY, scaleX); // Inverser X et Y pour compenser la rotation
                }
            window.draw(sprite);
        }
            

            // Marquage voiture de départ
            if (currentId == plateau.v_dep) {
                sf::CircleShape centerCircle;
                float radius = std::min(cellSizeX, cellSizeY) / 10;
                centerCircle.setRadius(radius);
                centerCircle.setFillColor(sf::Color(0,0,0,100));
                centerCircle.setPosition(j * cellSizeX + (cellSizeX / 2) - radius,
                                        i * cellSizeY + (cellSizeY / 2) - radius);
                window.draw(centerCircle);
            }
        }
    }
    
    //voiture selectioné
    voiture selectedCar = getvoiture(plateau, vo);

    float x = selectedCar.coord[1] * cellSizeX;
    float y = selectedCar.coord[0] * cellSizeY;
    float w = (selectedCar.ori == "horizontale") ? selectedCar.taille * cellSizeX : cellSizeX;
    float h = (selectedCar.ori == "verticale")   ? selectedCar.taille * cellSizeY : cellSizeY;

    sf::RectangleShape border(sf::Vector2f(w, h));
    border.setPosition(x, y);
    border.setFillColor(sf::Color::Transparent);
    border.setOutlineThickness(-3);
    border.setOutlineColor(sf::Color::Black);

    window.draw(border);


    //fin
    int finX=plateau.fin[0];int finY=plateau.fin[1];
    float rotation = 0;

    sf::Sprite endSprite;
    endSprite.setTexture(tex_out);

    float scaleImageX = cellSizeX / endSprite.getTexture()->getSize().x;
    float scaleImageY = cellSizeY / endSprite.getTexture()->getSize().y;

    if     (finX==0)                  {rotation = 270;endSprite.setScale(scaleImageY, scaleImageX);}
    else if(finX==plateau.taille[0]-1){rotation = 90;endSprite.setScale(scaleImageY, scaleImageX);}
    else if(finY==0)                  {rotation = 180;endSprite.setScale(scaleImageX, scaleImageY);}
    else if(finY==plateau.taille[1]-1){rotation = 0;endSprite.setScale(scaleImageX, scaleImageY);}
    else{
        endSprite.setTexture(tex_in);
    }

    endSprite.setOrigin(endSprite.getLocalBounds().width / 2, endSprite.getLocalBounds().height / 2);
    endSprite.setRotation(rotation);
    endSprite.setColor(sf::Color(255, 255, 255, 160));
    endSprite.setPosition(finY*cellSizeX+(cellSizeX/2),finX*cellSizeY+(cellSizeY/2));

    window.draw(endSprite);

    window.display();
}