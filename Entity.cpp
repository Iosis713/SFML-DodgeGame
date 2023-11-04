#include "Headers/Entity.hpp"

Entity::Entity(){};


std::pair<int, int> const Entity::getPosition()
{
    return position_;
};

void Entity::setPosition(int positionX, int positionY)
{
    position_.first = positionX;
    position_.second = positionY;
};
