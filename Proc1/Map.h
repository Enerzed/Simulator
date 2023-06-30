#pragma once
#define MAP_WIDTH 120
#define MAP_HEIGHT 90
#include "Cell.h"
#include "Wall.h"
#include "Food.h"
#include <iterator>
#include <iostream>

class Map
{
private:
	int x = MAP_WIDTH;
	int y = MAP_HEIGHT;
	std::vector<Entity> map;
	std::list<Cell*> cells;
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;
	sf::Color colors[6] = { sf::Color::Red, sf::Color::Green, sf::Color::Blue, sf::Color::Magenta, sf::Color::Cyan , sf::Color::Yellow };
	Random random;
public:
	Map()
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if ((i == 0 || i == MAP_HEIGHT - 1) || (j == 0 || j == MAP_WIDTH - 1))
				{
					Wall wall(j, i);
					map.push_back(wall);
				}
				else
				{
					Entity undefined(j, i);
					map.push_back(undefined);
				}
			}
		mapImage.loadFromFile("textures/mapTextures.png");
		mapTexture.loadFromImage(mapImage);
		mapSprite.setTexture(mapTexture);

		map.at(15 * MAP_WIDTH + 15).setName("cell");
		cells.push_back(new Cell(15, 15));

		map.at(20 * MAP_WIDTH + 20).setName("cell");
		cells.push_back(new Cell(20, 20));
	}

	void generateFood(int maxFood)
	{
		int tempI = random.generate(0, MAP_HEIGHT - 1);
		int tempJ = random.generate(0, MAP_WIDTH - 1);

		for (int i = 0; i < maxFood; i++)
			if (map.at(tempI * MAP_WIDTH + tempJ).getName() == "undefined")
			{
				map.at(tempI * MAP_WIDTH + tempJ).setName("food");
			}
	}

	void update()
	{
		//Iterator for cells
		auto i = cells.begin();
		
		//Decreasing energy by 1 (time)
		for (i = cells.begin(); i != cells.end(); i++)
			(*i)->setEnergy((*i)->getEnergy() - 1);
		//Deleting dead cells from list
		for (i = cells.begin(); i != cells.end();)
		{
			if ((*i)->getEnergy() <= 0)
			{
				std::cout << "DELETED CELL\n";
				map.at((*i)->getPosY() * MAP_WIDTH + (*i)->getPosX()).setName("food");
				i = cells.erase(i);
			}
			else
				i++;
		}
		for (i = cells.begin(); i != cells.end(); i++)
		{
			int posX = (*i)->getPosX();
			int posY = (*i)->getPosY();
			int seeX = (*i)->getSeeX();
			int seeY = (*i)->getSeeY();
			std::string tempName = map.at(seeY * MAP_WIDTH + seeX).getName();
			if (tempName == "undefined")
				switch ((*i)->getGen().none)
				{
				case 0:
				{
					(*i)->facingTurnRight();
					break;
				}
				case 1:
				{
					(*i)->facingTurnLeft();
					break;
				}
				case 5:
				{
					(*i)->go();
					map.at(seeY * MAP_WIDTH + seeX).setName("cell");
					if ((*i)->getEnergy() > 100)
					{
						std::cout << "CREATED\n";
						map.at(posY * MAP_WIDTH + posX).setName("cell");
						cells.push_back(new Cell(posX, posY));
						cells.back()->getGen().mutate();
					}
					else
						map.at(posY * MAP_WIDTH + posX).setName("undefined");
					break;
				}
				}
				else if (tempName == "food")
				{
					switch ((*i)->getGen().food)
					{
					case 0:
					{
						(*i)->facingTurnRight();
						break;
					}
					case 1:
					{
						(*i)->facingTurnLeft();
						break;
					}
					case 2:
					{
						map.at(seeY * MAP_WIDTH + seeX).setName("undefined");
						(*i)->setEnergy((*i)->getEnergy() + 50);
					}
					}
				}
				else if (tempName == "cell")
				{
					
				}
				else if (tempName == "wall")
				{
					switch ((*i)->getGen().wall)
					{
					case 0:
					{
						(*i)->facingTurnRight();
						break;
					}
					case 1:
					{
						(*i)->facingTurnLeft();
						break;
					}
					}
				}
		}
	}
	void draw(sf::RenderWindow& window, sf::Clock clock)
	{
		generateFood(1);
		update();
		//Drawing sprites
		for (int i = 0; i < MAP_HEIGHT; i++)
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if ((map.at(i * MAP_WIDTH + j)).getName() == "undefined")
					mapSprite.setTextureRect(sf::IntRect(0, 0, 8, 8));
				else if ((map.at(i * MAP_WIDTH + j)).getName() == "wall")
					mapSprite.setTextureRect(sf::IntRect(8, 0, 8, 8));
				else if ((map.at(i * MAP_WIDTH + j)).getName() == "food")
					mapSprite.setTextureRect(sf::IntRect(16, 0, 8, 8));
				else if ((map.at(i * MAP_WIDTH + j)).getName() == "cell")
				{
					mapSprite.setTextureRect(sf::IntRect(24, 0, 8, 8));
					mapSprite.setColor((map.at(i * MAP_WIDTH + j)).getColor());
				}
				mapSprite.setPosition(j * 8, i * 8);
				window.draw(mapSprite);
				mapSprite.setColor(sf::Color::White);
			}
	}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
};

