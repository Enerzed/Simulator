#pragma once
#include "Entity.h"
class Food :
    public Entity
{
private:
public:
    Food(int myPosX, int myPosY)
    {
        name = "food";
        posX = myPosX;
        posY = myPosY;
        color = sf::Color(0, 255, 0);
    }
    void update()
    {

    }
    Food& operator=(Food& other)
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

