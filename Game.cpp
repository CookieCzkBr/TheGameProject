#include "Game.h"

#include "MainMenuState.h"

Game::Game(GameConfig config)
	:	config(config), stateManager(config)
{
	this->gameWindow = std::make_unique<sf::RenderWindow>(sf::VideoMode(this->config.windowSize), this->config.appTitle, sf::Style::Close);
	this->game_dt = 0.f;
	this->backgroundClearColor = sf::Color(63, 63, 63, 255);
	this->stateManager.changeState(std::make_unique<MainMenuState>(this->stateManager));
	if (this->config.showConsoleLog)
	{
		std::cout << "<Game> Fully Constructed!" << std::endl;
	}
}

Game::~Game()
{
	if (this->config.showConsoleLog)
	{
		std::cout << "<Game> Deconstructed!" << std::endl;
	}
}

void Game::run()
{
	if (this->config.showConsoleLog)
	{
		std::cout << "<Game> Started Running!" << std::endl;
	}
	while (this->gameWindow->isOpen())
	{
		if (this->stateManager.isEmpty())
		{
			this->gameWindow->close();
		}
		else
		{
			while (std::optional <sf::Event> event = this->gameWindow->pollEvent())
			{
				this->stateManager.handleEvent(event);
			}
			this->update_dt();
			this->update();
			this->render();
		}
	}
	if (this->config.showConsoleLog)
	{
		std::cout << "<Game> Stoped Running!" << std::endl;
	}
}

void Game::update_dt()
{
	this->game_dt = this->gameClock.restart().asSeconds();
}

void Game::update()
{
	this->stateManager.update(this->game_dt);
}

void Game::render()
{
	this->gameWindow->clear(this->backgroundClearColor);
	this->stateManager.render(*this->gameWindow);
	this->gameWindow->display();
}
