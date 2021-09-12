#pragma once

#include<string>

class Map
{
private:
	std::string textureId;
	int scale;
	int tileSize;//For this project assuming tile input is square. Alternatively we can read from an xml but here We will be reading from a .txt file
public:
	Map(std::string textureId, int scale, int tileSize);

	~Map();

	void LoadMap(std::string filePath, int mapSizeX, int mapSizeY);

	//Source and target rectangles to render the tiles. (x,y) the posiiton of the tile
	void AddTile(int sourceRectX, int sourceRectY, int x, int y);
};

