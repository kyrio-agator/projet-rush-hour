#include "interface.h"




using grid=char**;

void affiche(grid g,int s){
    std::cout<<std::endl;
    for(int i=0;i<s;i++){
        for(int j=0;j<s;j++){
            std::cout<<g[i][j];
        }
        std::cout<<std::endl;
    }
}

void interfaceSFML()
{
    // Create a window with the title "SFML Window" and size 800x600
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Window");

    // Main loop that continues until the window is closed
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close the window if the close event is received
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Display the current frame
        window.display();
    }
}