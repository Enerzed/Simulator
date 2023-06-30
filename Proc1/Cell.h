#pragma once
#include "Entity.h"
class Cell :
    public Entity
{
private:
	int energy;
	int facing;
	int seeX, seeY;
	Gen gen;
	Random random;
public:
	Cell(int myPosX, int myPosY)
    {
		energy = 200;
        name = "cell";
        posX = myPosX;
        posY = myPosY;
		facing = random.generate(1, 8);
		updateSee();
		color = sf::Color::Green;
    }

	void updateSee()
	{
		switch (facing)
		{
		case 1:
		{
			seeX = posX + 1;
			seeY = posY;
			break;
		}
		case 2:
		{
			seeX = posX + 1;
			seeY = posY + 1;
			break;
		}
		case 3:
		{
			seeX = posX;
			seeY = posY + 1;
			break;
		}
		case 4:
		{
			seeX = posX - 1;
			seeY = posY + 1;
			break;
		}
		case 5:
		{
			seeX = posX - 1;
			seeY = posY;
			break;
		}
		case 6:
		{
			seeX = posX - 1;
			seeY = posY - 1;
			break;
		}
		case 7:
		{
			seeX = posX;
			seeY = posY - 1;
			break;
		}
		case 8:
		{
			seeX = posX + 1;
			seeY = posY - 1;
			break;
		}
		}
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

	void facingTurnRight()
	{
		if (facing == 8)
			facing = 1;
		else
			facing++;
		updateSee();
	}

	void facingTurnLeft()
	{
		if (facing == 1)
			facing = 8;
		else
			facing--;
		updateSee();
	}

	void go()
	{
		switch (facing)
		{
		case 1:
		{
			posX = posX + 1;
			posY = posY;
			break;
		}
		case 2:
		{
			posX = posX + 1;
			posY = posY + 1;
			break;
		}
		case 3:
		{
			posX = posX;
			posY = posY + 1;
			break;
		}
		case 4:
		{
			posX = posX - 1;
			posY = posY + 1;
			break;
		}
		case 5:
		{
			posX = posX - 1;
			posY = posY;
			break;
		}
		case 6:
		{
			posX = posX - 1;
			posY = posY - 1;
			break;
		}
		case 7:
		{
			posX = posX;
			posY = posY - 1;
			break;
		}
		case 8:
		{
			posX = posX + 1;
			posY = posY - 1;
			break;
		}
		}
		updateSee();
	}

	int getSeeX()
	{
		return seeX;
	}

	int getSeeY()
	{
		return seeY;
	}

	void setSeeX(int mySeeX)
	{
		seeX = mySeeX;
	}

	void setSeeY(int mySeeY)
	{
		seeY = mySeeY;
	}

	int getFacing()
	{
		return facing;
	}

	Cell(const Cell& other)
	{
		name = other.name;
		posX = other.posX;
		posY = other.posY;
		seeX = other.seeX;
		seeY = other.seeY;
		facing = other.facing;
		energy = other.energy;
		color = other.color;
	}

	Cell& operator=(const Cell& other)
	{
		if (this != &other)
		{
			name = other.name;
			posX = other.posX;
			posY = other.posY;
			seeX = other.seeX;
			seeY = other.seeY;
			facing = other.facing;
			energy = other.energy;
			color = other.color;
		}
		return *this;
	}
};

