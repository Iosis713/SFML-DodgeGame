#include "Headers/Block.hpp"

Block::Block(sf::Vector2f position, float const height, float const lenght, sf::Color color)
    : position_(position)
    , height_(height)
    , lenght_(lenght)
{
    rectangle_.setFillColor(color);
    rectangle_.setSize(sf::Vector2f(lenght_, height_));
    //origin in upper left corner
    rectangle_.setPosition(position_);
};

void Block::draw(sf::RenderWindow& i_window)
{
    rectangle_.setPosition(position_);
    i_window.draw(rectangle_);
};

float Block::getHeight() const
{
    return this-> height_;
}

float Block::getLenght() const
{
    return this-> lenght_;
}

sf::Vector2f const Block::getPosition()
{
    return this-> position_;
};

void Block::setPosition(sf::Vector2f newPosition)
{
    position_ = newPosition;
};

