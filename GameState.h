#pragma once

#include "State.h"

class GameState :
	public State
{
private:

public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();

	void endState();
	void updateKeybinds(const float& deltaTime);
	void render();
	void update(const float& deltaTime);
};

