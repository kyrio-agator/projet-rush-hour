# projet-rush-hour


## installer SFML
https://www.sfml-dev.org/download/sfml/2.5.0/  

**depuis minGW:**  
pacman -S mingw-w64-x86_64-sfml

## source librairie json  
https://github.com/nlohmann/json


## compilation + execution  

vider build/ avant de cmake  
### windows   
cd .\build\  
cmake ..\CMakeLists.txt -G "MinGW Makefiles"  
cmake --build .  
./rush-hour.exe  

### linux
cd .build/  
cmake ../CMakeLists.txt  
cmake --build .  
./rush-hour.exe  

## todo s4

✓ inversé les sprite  
netoyé tout le code car c'est le bordel  
✓ trouvé un moyen d'avoir l'IA qui donne les move au lieu de les executé lui meme  
resoudre le probleme de pointer de schrodinger ,crash random meme sans recompilation
    -> solution  ->  tout changer en vector
## timeline

**s1**  
✓ minimum jouable (pas interface graph)  
✓ definir le formal de plateau  

**s2**  
✓ chargement des plateau  (donné 2 plateau) (nimporte quelle taille)  
✓ interface graphique 1 joueur  
✓ commencé a reflechire sur l'IA  

**s3**  
✓ testé IA  
✓ comencé reflection site web  

**s4**  
-finir IA  
-finir programe  
-finir site web  

