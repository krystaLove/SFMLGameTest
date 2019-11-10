#include "GameState.h"
#include "AnimationManager.h"
#include <iostream>

GameState::GameState(sf::RenderWindow* window)
	:State(window)
{
	this->animationManager = new AnimationManager();
}

GameState::~GameState()
{

}

void GameState::initAnimationManager()
{
	this->animationManager->create();
}

void GameState::endState()
{
	std::cout << "Quiting GameState\n";
}

void GameState::updateKeybinds(const float& deltaTime)
{
	this->checkForQuit();
}

void GameState::render()
{

}

void GameState::update(const float& deltaTime)
{
	this->updateKeybinds(deltaTime);
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		std::cout << "Hello from GameState!\n";
}
