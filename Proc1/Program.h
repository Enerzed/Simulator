#include <iostream>
#include <random>
#include "Controls.h"
#include "Map.h"
#include <sstream>


class Program
{
private:
	sf::Clock clock;
	sf::Time mainStart;
	sf::Font font;
	Map map;
	Controls controls;
	int speed = 1;
	int x;
	int y;
	bool clickedCell = false;
	Cell displayCell;
public:
	Program()
	{

	}

	void run()
	{
		font.loadFromFile("Consolas.ttf");
		sf::Text numberOfCells("", font, 14);
		sf::Text cellInfo("", font, 14);
		sf::Vector2i position = sf::Mouse::getPosition();
		sf::RenderWindow window(sf::VideoMode(1240, 640), "Simulator", sf::Style::Close);
		controls.init(window);
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;

		while (window.isOpen())
		{
			float time = clock.getElapsedTime().asMicroseconds();
			clock.restart();
			time = time / 800;
			sf::Event event;
			while (window.pollEvent(event))
			{
				ImGui::SFML::ProcessEvent(event);
				if (event.type == sf::Event::Closed)
					window.close();
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					map.spawnCell(int(x / 16), int(y / 16));
				}
				if (event.type == sf::Event::MouseButtonPressed && sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					cellInfo.setString(map.getCellInfo(x / 16, y / 16));
				}
				if (event.type == sf::Event::MouseMoved)
				{
					x = event.mouseMove.x;
					y = event.mouseMove.y;
				}
			}
			controls.process(window, clock);
			map.setMaxIteration(controls.getGenSlider());
			map.setRequiredEnergyForDevision(controls.getRequiredEnergyForDevision());
			map.setEnergyPerPhotos(controls.getPhotosSlider());
			map.setDecreaseEnergy(controls.getDecreaseEnergy());
			numberOfCells.setString("Number of Cells: " + map.getNumberOfCells());
			numberOfCells.setPosition(660, 340);
			cellInfo.setPosition(660, 400);

			window.clear(sf::Color(0, 0, 0));
			window.draw(numberOfCells);
			window.draw(cellInfo);
			map.draw(window, controls.getSpeedSlider(), clock, controls.getFoodSlider(), controls.getIsPause());
			ImGui::SFML::Render(window);
			window.display();
		}
		ImGui::SFML::Shutdown();
	}
};