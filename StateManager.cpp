#include "StateManager.h"
#include "State.h"

StateManager::StateManager(GameConfig& config)
	:	config(config)
{
	if (this->isLogEnabled())
	{
		std::cout << "<StateManager> Constructed!" << std::endl;
	}
}

StateManager::~StateManager()
{
	if (this->isLogEnabled())
	{
		std::cout << "<StateManager> Deconstructed!" << std::endl;
	}
}

bool StateManager::isLogEnabled() const
{
	return this->config.showConsoleLog;
}

bool StateManager::isEmpty() const
{
	if (currentState)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void StateManager::changeState(std::unique_ptr<State> next_state)
{
	if (this->isLogEnabled())
	{
		std::cout << "<StateManager> Changing State!" << std::endl;

	}
	this->currentState = std::move(next_state);
}

void StateManager::handleEvent(std::optional<sf::Event>& event)
{
	this->currentState->handleEvent(event);
}

void StateManager::update(float dt)
{
	this->currentState->update(dt);
	if (this->currentState->getStateQuit())
	{
		this->currentState = nullptr;
	}
}

void StateManager::render(sf::RenderTarget& render_target)
{
	this->currentState->render(render_target);
}
