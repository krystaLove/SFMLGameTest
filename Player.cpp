#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace sf;
Player::Player(std::string image_fileName, float x, float y, float width, float height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;

	this->image.loadFromFile(image_fileName);
	this->texture.loadFromImage(this->image);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(IntRect(0, 0, width, height));
	this->sprite.setScale(2.f, 2.f);
};

void Player::update(float time) {

	this->move(time);

	switch (dir) 
	{
		case 0: dx = speed; dy = 0; break;
		case 1: dx = -speed; dy = 0; break;
		case 2: dy = speed; dx = 0; break;
		case 3: dy = -speed; dx = 0; break;
	}
	x += dx * time;
	y += dy * time;
	speed = 0;
	sprite.setPosition(x, y);
}
void Player::render(RenderWindow& window) {
	window.draw(this->sprite);
}
void Player::move(float time) {
	if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
	{
		dir = 1;
		speed = 0.15;
		currentFrame += 0.005 * time;
		sprite.setTextureRect(IntRect(32 * int(currentFrame), 62, 30, 60));
	}
	if (Keyboard::isKeyPressed(Keyboard::Right) || Keyboard::isKeyPressed(Keyboard::D))
	{
		dir = 0;
		speed = 0.15;
		currentFrame += 0.005 * time;

		sprite.setTextureRect(IntRect(32 * int(currentFrame), 193, 32, 60));
	}
	if (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W))
	{
		dir = 3;
		speed = 0.15;
		currentFrame += 0.005 * time;

		sprite.setTextureRect(IntRect(32 * int(currentFrame), 128, 30, 60));
	}
	if (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S))
	{
		dir = 2;
		speed = 0.15;
		currentFrame += 0.005 * time;

		sprite.setTextureRect(IntRect(32 * int(currentFrame), 0, 30, 60));
	}
	if (currentFrame > 6) currentFrame -= 6;
}