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
    std::vector<Entity> Objects;
	std::string name;
    sf::Texture texture;
    sf::Sprite sprite;
    int posX;
    int posY;
    bool isAlive;

public:
    Entity()
    {
        name = "undefined";
    }

    Entity(sf::Image myImage, int myPosX, int myPosY, std::string myName)
    {
        texture.loadFromImage(myImage);
        sprite.setTexture(texture);
        name = myName;
        posX = myPosX;
        posY = myPosY;
    }
   
    virtual void update(float time) = 0;

	std::string getName()
	{
		return name;
	}

	void setName(std::string myName)
	{
		name = myName;
	}

    Entity& operator=(Entity& other)
    {
        if (this != &other)
        {
            name = other.name;
            posX = other.posX;
            posY = other.posY;
        }
        return *this;
    }

    Entity(const Entity& other)
    {
        name = other.name;
        posX = other.posX;
        posY = other.posY;
    }
};

