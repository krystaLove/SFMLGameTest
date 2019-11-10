#include "Animation.h"

Animation::Animation(sf::Texture& t, int x, int y, int w, int h, int count, float speed, int step)
{
	this->speed = speed;
	this->sprite.setTexture(t);

	currentFrame = 0;
	isPlaying = true;
	flip = false;

	for (int i = 0; i < count; i++) {
		frames.push_back(sf::IntRect(x + i * step, y, w, h));
		frames_flip.push_back(sf::IntRect(x + i * step + w, y, -w, h));
	}
}

void Animation::tick(const float& deltaTime) {
	if (!this->isPlaying) return;
	this->currentFrame += this->speed * deltaTime;
	
	if (currentFrame > frames.size())
		currentFrame -= frames.size();

	this->sprite.setTextureRect(frames[currentFrame]);
	if (this->flip) sprite.setTextureRect(frames_flip[currentFrame]);
}
