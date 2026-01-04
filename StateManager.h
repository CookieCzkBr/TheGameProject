#pragma once

#include <iostream>
#include <memory>
#include <optional>

#include "Config.h"

class State;
namespace sf
{
	class Event;
	class RenderTarget;
}

class StateManager
{
private:
	std::unique_ptr<State> currentState;
	GameConfig& config;
public:
	StateManager(GameConfig& config);
	virtual ~StateManager();
	
	bool isLogEnabled() const;
	bool isEmpty() const;

	void changeState(std::unique_ptr<State> next_state);

	void handleEvent(std::optional<sf::Event>& event);
	void update(float dt);
	void render(sf::RenderTarget& render_target);
};

