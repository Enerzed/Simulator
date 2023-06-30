#pragma once
#include "Random.h"
//0 - turnRight
//1 - turnLeft
//2 - eat
//3 - kill
//4 - hold
//5 - go

class Gen
{
public:
	int none;
	int sameCell;
	int otherCell;
	int food;
	int wall;
	Random random;

	Gen()
	{
		int reaction;

		do reaction = random.generate(0, 5);
		while (reaction == 2 || reaction == 3);
		none = reaction;

		do reaction = random.generate(0, 5);
		while (reaction == 2 || reaction == 5);
		sameCell = reaction;

		do reaction = random.generate(0, 5);
		while (reaction == 2 || reaction == 5);
		otherCell = reaction;

		do reaction = random.generate(0, 5);
		while (reaction == 3 || reaction == 5);
		food = reaction;

		do reaction = random.generate(0, 5);
		while (reaction == 2 || reaction == 3 || reaction == 5);
		wall = reaction;
	}

	void mutate()
	{
		if (random.generate(0, 9) == 0)
		{
			int reaction;
			int gen = random.generate(0, 4);
			switch (gen)
			{
			case 0: {
				do reaction = random.generate(0, 5);
				while (reaction == 2 || reaction == 3);
				none = reaction;
				break;
			}
			case 1: {
				do reaction = random.generate(0, 5);
				while (reaction == 2 || reaction == 5);
				sameCell = reaction;
				break;
			}
			case 2: {
				do reaction = random.generate(0, 5);
				while (reaction == 2 || reaction == 5);
				otherCell = reaction;
				break;
			}
			case 3: {
				do reaction = random.generate(0, 5);
				while (reaction == 3 || reaction == 5);
				food = reaction;
				break;
			}
			case 4: {
				do reaction = random.generate(0, 5);
				while (reaction == 2 || reaction == 3 || reaction == 5);
				wall = reaction;
				break;
			}
			}
			
		}
	}

	Gen(const Gen& other)
	{
		none = other.none;
		sameCell = other.sameCell;
		otherCell = other.otherCell;
		food = other.food;
		wall = other.wall;;
	}

	Gen& operator=(const Gen& other)
	{
		if (this != &other)
		{
			none = other.none;
			sameCell = other.sameCell;
			otherCell = other.otherCell;
			food = other.food;
			wall = other.wall;
		}
		return *this;
	}

	bool operator == (const Gen& g)
	{
		if (none == g.none && sameCell == g.sameCell && otherCell == g.otherCell && food == g.food && wall == g.wall)
			return true;
		return false;
	}
};

