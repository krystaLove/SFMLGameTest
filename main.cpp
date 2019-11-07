#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Graphics.hpp>

#include <iostream>

#include "Player.h"
#include "tileMap.h"
#include "Game.h"

using namespace sf;

int main()
{

	Game game;
	game.run();

	return 0;
}