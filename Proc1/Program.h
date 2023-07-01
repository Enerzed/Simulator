#include <iostream>
#include <random>
#include "Controls.h"
#include "Map.h"


class Program
{
private:
	sf::Clock clock;
	sf::Time mainStart;
	Map map;
	Controls controls;
	int speed = 1;
	int x;
	int y;
public:
	Program()
	{
		
	}

	void run()
	{
		sf::Vector2i position = sf::Mouse::getPosition();
		sf::RenderWindow window(sf::VideoMode(1024, 640), "Simulator");
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
				if (event.type == sf::Event::MouseButtonPressed)
				{
					map.spawnCell(int(x / 16), int(y / 16));
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
			window.clear(sf::Color(255, 255, 255));
			map.draw(window, controls.getSpeedSlider(), clock, controls.getFoodSlider(), controls.getIsPause());
			ImGui::SFML::Render(window);
			window.display();
		}
		ImGui::SFML::Shutdown();
	}
};