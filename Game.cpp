#include "Game.h"
#include "Player.h";
#include "TileMap.h";

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include <fstream>

void Game::initRenderWindow()
{
	std::string title = "Empty title";
	sf::VideoMode window_bounds(800, 600);
	unsigned framePerSecond = 120;
	bool verticalSyncEnabled = 0;

	fstream fs("Config/window.ini");

	if (fs.is_open()) {
		getline(fs, title);
		fs >> window_bounds.width >> window_bounds.height;
		fs >> framePerSecond;
		fs >> verticalSyncEnabled;
	}

	fs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
	this->window->setFramerateLimit(framePerSecond);
	this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void Game::initTileMap()
{
	this->currentMap = new TileMap;
	this->currentMap->loadTileMap("maps/1.txt");
	this->currentMap->loadTileSet("images/map.png");
}

void Game::initHero()
{
	this->hero = new Player("images/hero.png", 200, 200, 30, 60);
}

Game::Game()
{
	initHero();
	initTileMap();
	initRenderWindow();
}

Game::~Game()
{
	delete this->window;
	delete this->hero;
	delete this->currentMap;
}

void Game::update()
{
	this->updateSFMLEvents();
	this->updateTime();
	this->hero->update(this->time);
}

void Game::render()
{
	this->window->clear();

	this->currentMap->renderMap(*this->window);
	this->hero->render(*this->window);
	

	this->window->display();
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::updateSFMLEvents()
{
	while (this->window->pollEvent(event))
	{
		if (this->event.type == sf::Event::Closed)
			this->window->close();
	}
}

void Game::updateTime()
{
	this->time = this->clock.getElapsedTime().asMicroseconds();
	this->clock.restart();
	this->time /= 800;
}
