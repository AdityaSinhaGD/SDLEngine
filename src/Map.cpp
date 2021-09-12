#include "Map.h"
#include<fstream>
#include "Game.h"
#include "EntityManager.h"
#include "Components/TileComponent.h"

extern EntityManager manager;

Map::Map(std::string textureId, int scale, int tileSize)
{
	this->textureId = textureId;
	this->scale = scale;
	this->tileSize = tileSize;
}

Map::~Map()
{
	
}

//Read map defined in text file and use it to load a grid of tiles
void Map::LoadMap(std::string filePath, int mapSizeX, int mapSizeY)
{
	std::fstream mapFile;
	mapFile.open(filePath);

	for (int y = 0; y < mapSizeY; y++)
	{
		for (int x = 0; x < mapSizeX; x++)
		{
			char ch;

			mapFile.get(ch);
			int sourceRectY = atoi(&ch) * tileSize;

			mapFile.get(ch);
			int sourceRectX = atoi(&ch) * tileSize;

			AddTile(sourceRectX, sourceRectY, x * (scale * tileSize), y * (scale * tileSize));
			mapFile.ignore();
			
		}
	}
	mapFile.close();
}

//Add new tile obj to the game scene
void Map::AddTile(int sourceRectX, int sourceRectY, int x, int y)
{
	Entity& newTile(manager.AddEntity("Tile", TILEMAP_LAYER)); //This will break the unique entitiy naming scheme for tile type but I can live with this for now.
	newTile.AddComponent<TileComponent>(sourceRectX, sourceRectY, x, y, tileSize, scale, textureId);
}
