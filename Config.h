#pragma once

#include <string>
#include <SFML/System/Vector2.hpp>

struct GameConfig
{
	bool showConsoleLog = false;
	std::string appTitle = "Game";
	sf::Vector2u windowSize = { 1440U, 810U };
};