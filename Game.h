#pragma once

#include "GameState.h"

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;

	std::stack<State*> states;

	float time;

	//Initialization
	void initRenderWindow();
	void initStates();

public:
	//Constructors / Destructors
	Game();
	~Game();

	//Functions
	void update();

	void endApplication();

	//Render
	void render();

	//Core
	void run();

	void updateSFMLEvents();

	//Updating delta time
	void updateTime();
};

