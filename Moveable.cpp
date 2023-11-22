#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float const lenght, float const height, sf::Color color)
    : Block::Block(position, lenght, height, color)
{
};

void Moveable::checkCollision(const std::unique_ptr<Block>& blockPtr)
{
    //std::cout << "checkColiision\n";
    //left top vertex
    if(position_.x >= blockPtr->getPosition().x
    && position_.x <= blockPtr->getPosition().x + blockPtr->getLenght()
    && position_.y >= blockPtr->getPosition().y
    && position_.y <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collisionStatus_ = true;
        blockPtr->setCollisionStatus(true);
    }
    //right top vertex
    else if(position_.x + lenght_ >= blockPtr->getPosition().x
         && position_.x + lenght_ <= blockPtr->getPosition().x + blockPtr->getLenght()
         && position_.y >= blockPtr->getPosition().y
         && position_.y <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collisionStatus_ = true;
        blockPtr->setCollisionStatus(true);
    }
    //bottop left vertex
    else if(position_.x >= blockPtr->getPosition().x
         && position_.x <= blockPtr->getPosition().x + blockPtr->getLenght()
         && position_.y + height_ >= blockPtr->getPosition().y
         && position_.y + height_ <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collisionStatus_ = true;
        blockPtr->setCollisionStatus(true);
    }
    //bottom right vertex
    else if(position_.x + lenght_ >= blockPtr->getPosition().x
         && position_.x + lenght_ <= blockPtr->getPosition().x + blockPtr->getLenght()
         && position_.y + height_ >= blockPtr->getPosition().y
         && position_.y + height_ <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collisionStatus_ = true;
        blockPtr->setCollisionStatus(true);
    }

    else
    {
        collisionStatus_ = false;
        blockPtr->setCollisionStatus(false);
    }
    std::cout << "collision status: " << collisionStatus_ << '\n';
}

sf::Vector2f const Moveable::getVelocity()
{
    return this -> velocity_;
}

void Moveable::setVelocity(sf::Vector2f newVelocity)
{
    velocity_ = newVelocity;
}

void Moveable::move()
{   
    //horizontal movement
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
    //horizontal interia
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
    }

    //vertical movement
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            direction_ = Direction::Up;

            if(velocity_.y > -maximumHorizontalVelocity)
            {
                velocity_.y -= friction_;
            }
            else if(velocity_.y > maximumHorizontalVelocity &&
                    velocity_.y < maximumHorizontalVelocity + friction_)
            {
                velocity_.y = -maximumHorizontalVelocity; 
            }
        }
    
    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            direction_ = Direction::Down;

            if(velocity_.y < maximumHorizontalVelocity)
            {
                velocity_.y += friction_;
            }
            else if(velocity_.y < maximumHorizontalVelocity &&
                    velocity_.y> maximumHorizontalVelocity - friction_)
            {
                velocity_.y = maximumHorizontalVelocity; 
            }
        }
    
    //slowing down vertical intertia
    else
    {        
        if(velocity_.y > 0.0 && velocity_.y <= friction_)
        {
            velocity_.y = 0.0;
        }
        else if(velocity_.y > 0.0)
        {
            velocity_.y -= friction_;
        }
        else if(velocity_.y < 0.0 && velocity_.y >= -friction_)
        {
            velocity_.y = 0.0;
        }
        else if(velocity_.y < 0.0)
        {
            velocity_.y += friction_;
        }
       
    }
}

void Moveable::updatePosition()
{
    position_.x += velocity_.x;
    position_.y += velocity_.y;
}



