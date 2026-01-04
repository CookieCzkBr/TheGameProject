#pragma once

#include <iostream>
#include <optional>

#include "State.h"

class MainMenuState :
    public State
{
private:
    virtual void onEnter() override;
    virtual void onExit() override;
public:
    MainMenuState(StateManager& state_manager);
    virtual ~MainMenuState();

    virtual void handleEvent(std::optional<sf::Event>& event) override;
    virtual void update(float dt) override;
    virtual void render(sf::RenderTarget& render_target) override;
};

