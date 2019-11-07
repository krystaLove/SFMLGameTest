#pragma once
#include <SFML/Graphics.hpp>
class Animation
{
private:
	std::vector<sf::IntRect> frames, frames_flip;
	float currentFrame, speed;

public:

	bool flip, isPlaying;
	sf::Sprite sprite;

	void tick(const float& deltaTime);

	Animation(sf::Texture &t, int x, int y, int w, int h, int count, float speed, int step);
};

