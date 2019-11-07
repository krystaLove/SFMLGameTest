#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class TileMap {
	
public:
	TileMap();
	void loadTileSet(std::string tileSet_path);
	void loadTileMap(std::string tileMap_path);
	void renderMap(RenderWindow& window);
private:
	int height, width;
	Image mapImage;
	Texture mapTexture;
	Sprite spriteMap;
	vector<string> map;
};

