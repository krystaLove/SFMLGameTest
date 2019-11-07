#pragma once

#include <vector>
#include <stack>
#include <iostream>

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class State
{
private:
	sf::RenderWindow* window;
	std::vector<sf::Texture> textures;
	bool quit;

public:
	State(sf::RenderWindow* window);
	virtual ~State();

	virtual void checkForQuit();
	bool getQuit() const;

	virtual void endState() = 0;
	virtual void updateKeybinds(const float& deltaTime) = 0;
	virtual void render() = 0;
	virtual void update(const float& deltaTime) = 0;
};

