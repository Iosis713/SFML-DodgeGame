#include "Headers/Moveable.hpp"

Moveable::Moveable(sf::Vector2f position, float const lenght, float const height, sf::Color color)
    : Block::Block(position, lenght, height, color)
{
};

void Moveable::checkCollision(std::unique_ptr<Block>& blockPtr)
{
    sf::Vector2f penetration_(0.0, 0.0);
    //std::cout << "checkColiision\n";
    //left top vertex
    if(position_.x >= blockPtr->getPosition().x
    && position_.x <= blockPtr->getPosition().x + blockPtr->getLenght()
    && position_.y >= blockPtr->getPosition().y
    && position_.y <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collidedVertex_ = CollidedVertex::LeftTop;
        setCollisionPosition(blockPtr, true);
    }
    //right top vertex
    else if(position_.x + lenght_ >= blockPtr->getPosition().x
         && position_.x + lenght_ <= blockPtr->getPosition().x + blockPtr->getLenght()
         && position_.y >= blockPtr->getPosition().y
         && position_.y <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collidedVertex_ = CollidedVertex::RightTop;
        setCollisionPosition(blockPtr, true);
    }
    //bottop left vertex
    else if(position_.x >= blockPtr->getPosition().x
         && position_.x <= blockPtr->getPosition().x + blockPtr->getLenght()
         && position_.y + height_ >= blockPtr->getPosition().y
         && position_.y + height_ <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collidedVertex_ = CollidedVertex::LeftBottom;
        setCollisionPosition(blockPtr, true);
    }
    //bottom right vertex
    else if(position_.x + lenght_ >= blockPtr->getPosition().x
         && position_.x + lenght_ <= blockPtr->getPosition().x + blockPtr->getLenght()
         && position_.y + height_ >= blockPtr->getPosition().y
         && position_.y + height_ <= blockPtr->getPosition().y + blockPtr->getHeight())
    {
        collidedVertex_ = CollidedVertex::RightBottom;
        setCollisionPosition(blockPtr, true);
    }

    else
    {
        collisionStatus_ = false;
        blockPtr->setCollisionStatus(false);
        collidedVertex_ = CollidedVertex::None;
    }
    std::cout << "collision status: " << collisionStatus_ << '\n';
}

sf::Vector2f const Moveable::getVelocity()
{
    return this -> velocity_;
}

void Moveable::setCollisionPosition(std::unique_ptr<Block>& blockPtr, bool status)
{
    if(status == false)
    {
        collisionStatus_ = status;
        blockPtr->setCollisionStatus(status);
    }

    else
    {   
        collisionStatus_ = status;
        blockPtr->setCollisionStatus(status);

        float penetrationX_; //penetration in y direction is not necessery
        switch(collidedVertex_)
        {
            case CollidedVertex::LeftTop:
                penetrationX_ = blockPtr->getPosition().x
                               + blockPtr->getLenght()
                               - position_.x;
                
                if(penetrationX_ > abs(velocity_.x))
                {
                    position_.y = blockPtr->getPosition().y
                                + blockPtr->getHeight();
                    
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        velocity_.y = 0.0;
                    }
                }

                else
                {
                    position_.x = blockPtr->getPosition().x
                                + blockPtr->getLenght();
                    
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        velocity_.x = 0.0;
                    }
                }
                break;
            
            case CollidedVertex::RightTop:
                penetrationX_ = position_.x
                              + lenght_
                              - blockPtr->getPosition().x;
                
                if(penetrationX_ > velocity_.x)
                {
                    position_.y = blockPtr->getPosition().y
                                + blockPtr->getHeight();
                    
                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    {
                        velocity_.y = 0.0;
                    }
                }

                else
                {
                    position_.x = blockPtr->getPosition().x
                                - lenght_;

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        velocity_.x = 0.0;
                    }
                }
                break;

            case CollidedVertex::LeftBottom:
                penetrationX_ = blockPtr->getPosition().x
                              + blockPtr->getLenght()
                              - position_.x;

                if(penetrationX_ > abs(velocity_.x))
                {
                    position_.y = blockPtr->getPosition().y
                                - height_;

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        velocity_.y = 0;
                    }
                }
                else
                {
                    position_.x = blockPtr->getPosition().x
                                + blockPtr->getLenght();

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
                    {
                        velocity_.x = 0.0;
                    }
                }
                break;

            case CollidedVertex::RightBottom:
                penetrationX_ = position_.x
                              + lenght_
                              - blockPtr->getPosition().x;

                if(penetrationX_ > velocity_.x)
                {
                    position_.y = blockPtr->getPosition().y
                               - height_;

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    {
                        velocity_.y = 0.0;
                    }
                }

                else
                {
                    position_.x = blockPtr->getPosition().x
                                - lenght_;

                    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
                    {
                        velocity_.x = 0.0;
                    }
                }
                break;
            
            case CollidedVertex::None:
                break;
        }
    }
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



