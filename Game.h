#pragma once

#include "Config.h"
#include "StateManager.h"
#include "State.h"

#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
private:
	std::unique_ptr<sf::RenderWindow> gameWindow;
	GameConfig config;
	StateManager stateManager;

	sf::Clock gameClock;
	float game_dt;

	sf::Color backgroundClearColor;
public:
	Game(GameConfig config);
	virtual ~Game();

	void run();
	void update_dt();
	void update();
	void render();
};

