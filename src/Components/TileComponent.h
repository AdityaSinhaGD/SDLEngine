#pragma once

#include <SDL.h>
#include <glm/glm.hpp>
#include "../EntityManager.h"
#include "../AssetManager.h"

class TileComponent :public Component
{
public:
	SDL_Texture* texture;
	SDL_Rect sourceRectangle;
	SDL_Rect targetRectangle;
	glm::vec2 position;

	TileComponent(int sourceRectX, int sourceRectY, int x, int y, int tileSize, int tileScale, std::string assetTextureId)
	{
		texture = Game::assetManager->GetTexture(assetTextureId);

		sourceRectangle.x = sourceRectX;
		sourceRectangle.y = sourceRectY;
		sourceRectangle.w = tileSize;
		sourceRectangle.h = tileSize;

		targetRectangle.x = x;
		targetRectangle.y = y;
		targetRectangle.w = tileSize * tileScale;
		targetRectangle.h = tileSize * tileScale;

		position.x = x;
		position.y = y;
	}

	~TileComponent()
	{
		SDL_DestroyTexture(texture);
	}

	//Update tile positions based on Camera values.
	void Update(float deltaTime) override
	{
		targetRectangle.x = position.x - Game::camera.x;
		targetRectangle.y = position.y - Game::camera.y;
	}

	void Render() override
	{
		TextureManager::DrawTexture(texture, sourceRectangle, targetRectangle, SDL_FLIP_NONE);
	}
};