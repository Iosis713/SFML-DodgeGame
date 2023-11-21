#include <iostream>
#include "Headers/Block.hpp"
#include "Headers/Global.hpp"
#include "Headers/Moveable.hpp"
#include <SFML/Graphics.hpp>

#include <chrono>
#include <memory>
#include <thread>

int main()
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Dodge Game");

    //Block block1(sf::Vector2f(100.f, 200.f), 100.f, 200.f, sf::Color::Green);
    std::unique_ptr<Block> blockPtr1 = std::make_unique<Block>(sf::Vector2f(100.f, 200.f), 100.f, 200.f, sf::Color::Green);
    Moveable moveable1(sf::Vector2f(800.f, 250.f), 100.f, 100.f, sf::Color::Blue);
    
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
        
        blockPtr1->draw(window);
        
        //moveable test
        
        moveable1.move();
        moveable1.checkCollision(blockPtr1);
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

