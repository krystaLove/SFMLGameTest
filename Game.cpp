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

void Game::initStates()
{
	this->states.push(new GameState(this->window));
}

Game::Game()
{

	initRenderWindow();
	initStates();
}

Game::~Game()
{
	delete this->window;

	while (!this->states.empty()) {
		delete(this->states.top());

		this->states.pop();
	}
}

void Game::update()
{
	this->updateSFMLEvents();
	this->updateTime();

	if (!this->states.empty()) {
		this->states.top()->update(this->time);
		if (this->states.top()->getQuit()) {
			this->states.top()->endState();
			delete this->states.top();
			this->states.pop();
		}
	}
	else {
		this->endApplication();
		this->window->close();
	}
}

void Game::endApplication()
{
	std::cout << "Closing application!\n";
}

void Game::render()
{
	this->window->clear();

	if (!this->states.empty())
		this->states.top()->render();

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
