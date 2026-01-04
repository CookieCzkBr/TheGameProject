#include "MainMenuState.h"
#include "StateManager.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>

MainMenuState::MainMenuState(StateManager& state_manager)
	:	State(state_manager)
{
	if (this->stateManager.isLogEnabled())
	{
		std::cout << "<MainMenuState> Constructed!" << std::endl;
	}
	this->onEnter();
}

MainMenuState::~MainMenuState()
{
	if (this->stateManager.isLogEnabled())
	{
		std::cout << "<MainMenuState> Deconstructed!" << std::endl;
	}
}

void MainMenuState::onEnter()
{
	if (this->stateManager.isLogEnabled())
	{
		std::cout << "<MainMenuState> Entering State!" << std::endl;
	}
}

void MainMenuState::onExit()
{
	if (this->stateManager.isLogEnabled())
	{
		std::cout << "<MainMenuState> Exiting State!" << std::endl;
	}
}

void MainMenuState::handleEvent(std::optional<sf::Event>& event)
{
	if (event->is<sf::Event::Closed>())
	{
		if (this->stateManager.isLogEnabled())
		{
			std::cout << "<MainMenuState> Window Closed" << std::endl;
		}
		this->stateQuit = true;
	}
	if (const sf::Event::KeyPressed* keyPressed = event->getIf<sf::Event::KeyPressed>())
	{
		if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
		{
			this->stateQuit = true;
		}
	}
}

void MainMenuState::update(float dt)
{
}

void MainMenuState::render(sf::RenderTarget& render_target)
{
	//render_target.draw();
}
