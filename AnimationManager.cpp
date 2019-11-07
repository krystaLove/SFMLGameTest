#include "AnimationManager.h"

AnimationManager::AnimationManager()
{

}

void AnimationManager::create(std::string name, sf::Texture& t, int x, int y, int w, int h, int count, int speed, int step)
{
	this->animList[name] = Animation(t, x, y, w, h, count, speed, step);
	this->currentAnim = name;
}

void AnimationManager::draw(sf::RenderWindow& window, int x, int y) {
	this->animList[this->currentAnim].sprite.setPosition(x, y);
	window.draw(this->animList[this->currentAnim].sprite);
}

void AnimationManager::setAnimation(std::string name)
{
	this->currentAnim = name;
}

void AnimationManager::flip(bool value)
{
	this->animList[this->currentAnim].flip = value;
}

void AnimationManager::tick(const float& deltaTime)
{
	this->animList[this->currentAnim].tick(deltaTime);
}

void AnimationManager::pause()
{
	this->animList[this->currentAnim].isPlaying = false;
}

void AnimationManager::play()
{
	this->animList[this->currentAnim].isPlaying = true;
}
