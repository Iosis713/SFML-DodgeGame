#pragma once
#include <SFML/Graphics.hpp>

class Entity
{
protected:
    std::pair<int, int> position_;

public:
    Entity();
    virtual ~Entity();

    virtual void draw();
    
    std::pair<int, int> const getPosition();       

    void setPosition(int positionX, int positionY);

}

