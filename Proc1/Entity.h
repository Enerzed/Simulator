#pragma once
#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <SFML/Graphics.hpp> 
#include "Gen.h"

class Entity
{
protected:
    sf::Color color;
	std::string name;
    int posX;
    int posY;
public:
    Entity()
    {
        name = "undefined";
        posX = 0;
        posY = 0;
        bool isAlive = true;
        color = sf::Color::White;
    }

    Entity(int myPosX, int myPosY)
    {
        name = "undefined";
        posX = myPosX;
        posY = myPosY;
        bool isAlive = true;
        color = sf::Color::White;
    }

	std::string getName()
	{
		return name;
	}

	void setName(std::string myName)
	{
		name = myName;
	}

    int getPosX()
    {
        return posX;
    }

    int getPosY()
    {
        return posY;
    }

    void setPosX(int myPosX)
    {
        posX = myPosX;
    }

    void setPosY(int myPosY)
    {
        posY = myPosY;
    }

    sf::Color getColor()
    {
        return color;
    }

    void setColor(sf::Color myColor)
    {
        color = myColor;
    }

    Entity& operator=(const Entity& other)
    {
        if (this != &other)
        {
            name = other.name;
            posX = other.posX;
            posY = other.posY;
            color = other.color;
        }
        return *this;
    }

    Entity(const Entity& other)
    {
        name = other.name;
        posX = other.posX;
        posY = other.posY;
        color = other.color;
    }
};

