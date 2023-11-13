#include "Headers/Global.hpp"
#include <iostream>
#include "Headers/Block.hpp"
#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dodge Game");

    sf::Vector2f pos1(200.f, 400.f);

    Block block1(pos1, 40.f, 200.f);
    
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        window.clear();
        
        block1.draw(window);

        window.display();
    }

    return 0;
}

