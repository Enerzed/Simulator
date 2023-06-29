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
public:
	Program()
	{
		
	}

	void run()
	{
		sf::RenderWindow window(sf::VideoMode(1240, 720), "Simulator");
		controls.init(window);

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
			}
			controls.process(window, clock);
			window.clear(sf::Color(255, 255, 255));
			map.draw(window, clock);
			ImGui::SFML::Render(window);
			window.display();
		}
		ImGui::SFML::Shutdown();
	}
};