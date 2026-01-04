#pragma once

#include <iostream>
#include <optional>

class StateManager;
namespace sf
{
	class Event;
	class RenderTarget;
}
class State
{
protected:
	StateManager& stateManager;

	virtual void onEnter() = 0;
	virtual void onExit() = 0;
	bool stateQuit = false;
public:
	State(StateManager& state_manager);
	virtual ~State();

	virtual void handleEvent(std::optional<sf::Event>& event) = 0;
	virtual void update(float dt) = 0;
	virtual void render(sf::RenderTarget& render_target) = 0;

	virtual bool getStateQuit() const;
};

