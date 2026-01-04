#include "State.h"
#include "StateManager.h"

State::State(StateManager& state_manager)
	:	stateManager(state_manager)
{
	if (this->stateManager.isLogEnabled())
	{
		std::cout << "<State> Constructed!" << std::endl;
	}
}

State::~State()
{
	if (this->stateManager.isLogEnabled())
	{
		std::cout << "<State> Deconstructed!" << std::endl;
	}
}

bool State::getStateQuit() const
{
	return this->stateQuit;
}
