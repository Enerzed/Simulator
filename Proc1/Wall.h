#pragma once
#include "Entity.h"
class Wall :
    public Entity
{
private:
public:
    Wall(int myPosX, int myPosY)
    {
        name = "wall";
        posX = myPosX;
        posY = myPosY;
        color = sf::Color(50, 50, 50);
    }
    void update()
    {
        int a;
    }
    Wall& operator=(Wall& other)
    {
        if (this != &other)
        {
            name = other.name;
            posX = other.posX;
            posY = other.posY;
        }
        return *this;
    }
};

