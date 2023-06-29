#pragma once
#include <SFML/Graphics.hpp>
#include "imgui.h"
#include "imgui-SFML.h"

class Controls
{
private:
public:
	Controls()
	{

	}
	void init(sf::RenderWindow& window)
	{
		ImGui::SFML::Init(window);
	}
	void process(sf::RenderWindow& window, sf::Clock deltaClock)
	{
		ImGui::SFML::Update(window, deltaClock.restart());
		ImGui::Begin("Controls");
		ImGui::End();
	}
};

