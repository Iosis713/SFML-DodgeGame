#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Block
{
protected:
    sf::Vector2f position_;
    float const height_;
    float const lenght_;
    sf::RectangleShape rectangle_;
    
public:
    Block(sf::Vector2f position, float const height, float const lenght, sf::Color color);

    void draw(sf::RenderWindow& i_window);
    float getHeight() const;
    float getLenght() const;
    sf::Vector2f const getPosition();       

    void setPosition(sf::Vector2f newPosition);
};

