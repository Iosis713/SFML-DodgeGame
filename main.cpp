#include "Headers/Global.hpp"
#include <iostream>
#include "Headers/Block.hpp"
#include "Headers/Moveable.hpp"
#include <SFML/Graphics.hpp>

#include <chrono>
#include <thread>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dodge Game");

    Block block1(sf::Vector2f(200.f, 400.f), 40.f, 200.f);
    Moveable moveable1(sf::Vector2f(100.f, 50.f), 80.f, 300.f);
    
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
        
        //moveable test
        moveable1.move();
        moveable1.updatePosition();
        moveable1.draw(window);

        window.display();
        {
            using namespace std::chrono_literals;
            std::this_thread::sleep_for(20ms);
        }
    }

    return 0;
}

