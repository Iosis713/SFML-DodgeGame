#include "Headers/Block.hpp"

Block::Block(sf::Vector2f position, float height, float lenght)
    : position_(position)
    , height_(height)
    , lenght_(lenght)
{};

void Block::draw(sf::RenderWindow& i_window)
{
    sf::RectangleShape rectangle;
    rectangle.setSize(sf::Vector2f(lenght_, height_));
    rectangle.setOutlineThickness(height_/5);
    rectangle.setOutlineColor(sf::Color::Yellow);
    rectangle.setFillColor(sf::Color::Green);
    rectangle.setPosition(position_);
    i_window.draw(rectangle);
    
};

sf::Vector2f const Block::getPosition()
{
    return this-> position_;
};

void Block::setPosition(sf::Vector2f newPosition)
{
    position_ = newPosition;
};
