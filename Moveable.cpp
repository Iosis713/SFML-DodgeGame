#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float lenght, float height)
    : Block::Block(position, lenght, height)
{
    //Block::Block(position, lenght, height)
};

sf::Vector2f Moveable::getVelocity()
{
    return this -> velocity_;
}

void Moveable::setVelocity(sf::Vector2f newVelocity)
{
    velocity_ = newVelocity;
}

void Moveable::move()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            direction_ = Direction::Left;

            if(velocity_.x > -maximumHorizontalVelocity)
            {
                velocity_.x -= friction_; //inertia
            }
            else if(velocity_.x > -maximumHorizontalVelocity &&
                    velocity_.x < -maximumHorizontalVelocity + friction_)
            {
                velocity_.x = -maximumHorizontalVelocity; 
            }
        }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            direction_ = Direction::Right;

            if(velocity_.x < maximumHorizontalVelocity)
            {
                velocity_.x += friction_;
            }
            else if(velocity_.x < maximumHorizontalVelocity &&
                    velocity_.x > maximumHorizontalVelocity - friction_)
            {
                velocity_.x = maximumHorizontalVelocity; 
            }
        }

    //slowing down intertia
    else
    {
        if(velocity_.x > 0.0 && velocity_.x <= friction_)
        {
            velocity_.x = 0.0;
        }
        else if(velocity_.x > 0.0)
        {
            velocity_.x -= friction_;
        }
        else if(velocity_.x < 0.0 && velocity_.x >= -friction_)
        {
            velocity_.x = 0.0;
        }
        else if(velocity_.x < 0.0)
        {
            velocity_.x += friction_;
        }
        /*else
        {
            velocity_.x = 0.0;
        }
        */
    }
}

void Moveable::updatePosition()
{
    position_.x += velocity_.x;
    position_.y += velocity_.y;
}

