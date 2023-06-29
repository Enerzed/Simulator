#pragma once
#include "Entity.h"
class Cell :
    public Entity
{
private:
	int energy;
	int facing;
	enum { right, left, up, down, rightUp, rightDown, leftUp, leftDown } facing;
	Gen gen;
	sf::Color color;
public:
    Cell(int myPosX, int myPosY)
    {
        name = "cell";
        posX = myPosX;
        posY = myPosY;
    }

	Gen& getGen()
	{
		return gen;
	}

	void setGen(Gen myGen)
	{
		gen = myGen;
	}

	int getEnergy()
	{
		return energy;
	}

	void setEnergy(int myEnergy)
	{
		energy = myEnergy;
	}
};

