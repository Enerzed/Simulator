#pragma once
#define MAP_WIDTH 120
#define MAP_HEIGHT 90
#include "Entity.h"

class Map
{
private:
	int x = MAP_WIDTH;
	int y = MAP_HEIGHT;
	std::vector<Entity> map;
	sf::Image mapImage;
	sf::Texture mapTexture;
	sf::Sprite mapSprite;
	std::random_device rd;
public:
	Map()
	{
		for (int i = 0; i < MAP_HEIGHT; i++)
			for (int j = 0; j < MAP_WIDTH; j++)
			{
				if ((i == 0 || i == MAP_HEIGHT - 1) || (j == 0 || j == MAP_WIDTH - 1))
				{
					Entity wall(j, i, "wall");
					map.push_back(wall);
				}
				else
				{
					Entity undefined(j, i, "undefined");
					map.push_back(undefined);
				}
			}
		mapImage.loadFromFile("textures/mapTextures.png");
		mapTexture.loadFromImage(mapImage);
		mapSprite.setTexture(mapTexture);
	}
	void update(int maxFood, sf::Clock clock)
	{
		std::mt19937 generate(rd());
		std::uniform_int_distribution<> distributeI(0, 89);
		std::uniform_int_distribution<> distributeJ(0, 119);
		int tempI = distributeI(generate);
		int tempJ = distributeJ(generate);

		for (int i = 0; i < maxFood; i++)
			if (map.at(tempI * MAP_WIDTH + tempJ).getName() == "undefined")
			{
				Entity food(tempI, tempJ, "food");
				map.at(tempI * MAP_WIDTH + tempJ) = food;
			}
	}
	void draw(sf::RenderWindow& window, sf::Clock clock)
	{
		update(1, clock);
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
					mapSprite.setTextureRect(sf::IntRect(24, 0, 8, 8));
				mapSprite.setPosition(j * 8, i * 8);
				window.draw(mapSprite);
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

