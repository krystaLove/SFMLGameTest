#pragma once

#include "Animation.h"

#include <map>
class AnimationManager
{
private:
	std::string currentAnim;
	std::map<std::string, Animation> animList;

public:
	AnimationManager();

	void create(std::string name, sf::Texture& t, int x, int y, int w, int h, int count, int speed, int step);

	void draw(sf::RenderWindow& window, int x = 0, int y = 0);

	void setAnimation(std::string name);

	void flip(bool value);

	void tick(const float& deltaTime);

	void pause();

	void play();
};

