#pragma once

#include "State.h"

class GameState :
	public State
{
private:
	AnimationManager *animationManager;
public:
	GameState(sf::RenderWindow* window);
	virtual ~GameState();
	void initAnimationManager();
	void endState();
	void updateKeybinds(const float& deltaTime);
	void render();
	void update(const float& deltaTime);
};

