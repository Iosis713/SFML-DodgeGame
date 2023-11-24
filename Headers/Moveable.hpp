#pragma once
//#include "Global.hpp"
#include <cmath>
#include "Block.hpp"
#include <SFML/Graphics.hpp>


class Moveable : public Block
{
protected:
    enum class CollidedVertex{
        LeftTop,
        RightTop,
        LeftBottom,
        RightBottom,
        None
    };

    enum class Direction{
        Left,
        Right,
        Up,
        Down
    };

    CollidedVertex collidedVertex_ = CollidedVertex::None;
    Direction direction_ = Direction::Right;
    sf::Vector2f velocity_;
    float maximumHorizontalVelocity = 5.f;
    float friction_ = 0.2f;

public:

    Moveable(sf::Vector2f position, float const lenght, float const height, sf::Color color);
    sf::Vector2f const getVelocity();
    void setCollisionPosition(std::unique_ptr<Block>& blockPtr, bool status);
    void setVelocity(sf::Vector2f newVelocity);
    void updatePosition();
    void move();
    void checkCollision(std::unique_ptr<Block>& blockPtr);
};

