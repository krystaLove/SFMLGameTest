#include "tileMap.h"
#include <fstream>
#include <iostream>

using namespace std;
using namespace sf;

TileMap::TileMap()
{
	this->height = 0;
	this->width = 0;
}

void TileMap::loadTileSet(std::string tileSet_path)
{
	this->mapImage.loadFromFile(tileSet_path);
	this->mapTexture.loadFromImage(mapImage);
	this->spriteMap.setTexture(mapTexture);
}

void TileMap::loadTileMap(std::string tileMap_path)
{
	ifstream input_map(tileMap_path);

	if (!input_map.is_open()) return;

	input_map >> height >> width;
	std::string stroke;
	while (!input_map.eof()) {
		getline(input_map, stroke);
		if (stroke != "")
			map.push_back(stroke);
	}
	input_map.close();
}

void TileMap::renderMap(RenderWindow& window) {
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map[i].size(); j++) {
			if(map[i][j] == ' ') spriteMap.setTextureRect(IntRect(0, 0, 32, 32));
			if (map[i][j] == 's')  spriteMap.setTextureRect(IntRect(32, 0, 32, 32));
			if ((map[i][j] == '0')) spriteMap.setTextureRect(IntRect(64, 0, 32, 32));
			spriteMap.setPosition(j * 32, i * 32);
			window.draw(spriteMap);
		}
	}
}
