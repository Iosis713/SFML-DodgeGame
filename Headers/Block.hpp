#pragma once
#include <SFML/Graphics.hpp>

class Block
{
protected:
    sf::Vector2f position_;
    float height_;
    float lenght_;
public:
    Block(sf::Vector2f position, float height, float lenght);

    void draw(sf::RenderWindow& i_window);
    
    sf::Vector2f const getPosition();       

    void setPosition(sf::Vector2f newPosition);
};

