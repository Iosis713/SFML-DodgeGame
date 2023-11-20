#pragma once
//#include "Global.hpp"
#include "Block.hpp"
#include <SFML/Graphics.hpp>


class Moveable : public Block
{
protected:
    enum class Direction{
        Left,
        Right,
        Up,
        Down
    };

    Direction direction_ = Direction::Right;
    sf::Vector2f velocity_;
    float maximumHorizontalVelocity = 5.f;
    float friction_ = 0.2f;

public:

    Moveable(sf::Vector2f position, float lenght, float height);
    sf::Vector2f getVelocity();
    void setVelocity(sf::Vector2f newVelocity);
    void updatePosition();
    void move();
};

