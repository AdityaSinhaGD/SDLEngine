#pragma once
#include "../EntityManager.h"
#include <glm/glm.hpp>
#include<SDL.h>
#include "../Game.h"

class TransformComponent :public Component
{
public:

	glm::vec2 position;

	int width;
	int height;
	int scale;

	TransformComponent(int posX, int posY, int width, int height, int scale)
	{
		position = glm::vec2(posX, posY);
		
		this->width = width;
		this->height = height;
		this->scale = scale;
	}

	void Initialize() override
	{

	}

	void Update(float deltaTime) override
	{
		
	}

	void Render() override
	{
		/*SDL_Rect rectTransform = {
			(int)position.x,
			(int)position.y,
			width,
			height
		};

		SDL_SetRenderDrawColor(Game::renderer, 255, 255, 255, 255);
		SDL_RenderFillRect(Game::renderer, &rectTransform);*/
	}
};


