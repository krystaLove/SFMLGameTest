#pragma once

#include <SFML/Graphics.hpp>

class Player
{
public:
	Player(std::string image_fileName, float x, float y, float w, float h);
	void update(float time);
	void move(float time);
	void render(sf::RenderWindow&);

private:
	float currentFrame = 0;
	int dir = 0;
	float x, y;
	float width, height;
	float dx = 0, dy = 0;
	float speed = 0;
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
};

