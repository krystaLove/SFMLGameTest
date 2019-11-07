#pragma once

#include "Player.h"
#include "tileMap.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Game
{
private:
	//Variables
	sf::RenderWindow* window;
	sf::Event event;
	sf::Clock clock;
	Player *hero;
	TileMap *currentMap;

	float time;

	//Initialization
	void initRenderWindow();
	void initTileMap();
	void initHero();
public:
	//Constructors / Destructors
	Game();
	~Game();

	//Functions
	void update();
	void render();
	void run();
	void updateSFMLEvents();
	void updateTime();
};

