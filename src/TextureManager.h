#pragma once

#include "./Game.h"

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(const char* filePath);
	static void DrawTexture(SDL_Texture* texture, SDL_Rect sourceRectangle, SDL_Rect targetRectangle, SDL_RendererFlip flip);
};

