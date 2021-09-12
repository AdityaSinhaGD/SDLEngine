#pragma once
#include "../EntityManager.h"
#include <SDL.h>
#include "../TextureManager.h"
#include "../AssetManager.h"
#include "TransformComponent.h"
#include "../Animation.h"

class SpriteComponent :public Component
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect sourceRectangle;
	SDL_Rect targetRectangle;

	bool isAnimated;
	int numberOfFrames;
	int animationSpeed;
	bool isFixed;

	std::map<std::string, Animation> animations;
	std::string currentAnimationName;
	unsigned int animationIndex = 0;

public:
	SDL_RendererFlip spriteFlip = SDL_FLIP_NONE;

	SpriteComponent(const char* filePath)
	{
		isAnimated = false;
		isFixed = false;
		SetTexture(filePath);
	}

	SpriteComponent(std::string id, int numberOfFrames, int animationSpeed, bool hasDirections, bool isFixed)
	{
		this->isAnimated = true;
		this->numberOfFrames = numberOfFrames;
		this->animationSpeed = animationSpeed;
		this->isFixed = isFixed;

		if (hasDirections)
		{
			//todo process directions
			Animation downAnimation = Animation(0, numberOfFrames, animationSpeed);
			Animation rightAnimation = Animation(1, numberOfFrames, animationSpeed);
			Animation leftAnimation = Animation(2, numberOfFrames, animationSpeed);
			Animation upAnimation = Animation(3, numberOfFrames, animationSpeed);

			animations.emplace("DownAnimation", downAnimation);
			animations.emplace("RightAnimation", rightAnimation);
			animations.emplace("LeftAnimation", leftAnimation);
			animations.emplace("UpAnimation", upAnimation);

			this->animationIndex = 0;
			this->currentAnimationName = "DownAnimation";

		}
		else
		{
			//todo process if no directions
			Animation singleAnimation = Animation(0,numberOfFrames,animationSpeed);
			animations.emplace("SingleAnimation", singleAnimation);
			this->animationIndex = 0;
			this->currentAnimationName = "SingleAnimation";
	
		}
		PlayAnimation(this->currentAnimationName);
		SetTexture(id);
	}

	void PlayAnimation(std::string animationName)
	{
		numberOfFrames = animations[animationName].numberOfFrames;
		animationIndex = animations[animationName].index;
		animationSpeed = animations[animationName].animationSpeed;
		currentAnimationName = animationName;
	}

	void SetTexture(std::string assetTextureId)
	{
		texture = Game::assetManager->GetTexture(assetTextureId);
	}

	void Initialize() override
	{
		transform = owner->GetComponent<TransformComponent>();
		sourceRectangle.x = 0;
		sourceRectangle.y = 0;
		sourceRectangle.w = transform->width;
		sourceRectangle.h = transform->height;
	}

	void Update(float deltaTime) override
	{
		if (isAnimated)
		{
			sourceRectangle.x = sourceRectangle.w * static_cast<int>((SDL_GetTicks() / animationSpeed) % numberOfFrames);
		}
		sourceRectangle.y = animationIndex * transform->height;

		targetRectangle.x = static_cast<int>(transform->position.x) - (isFixed ? 0 : Game::camera.x);
		targetRectangle.y = static_cast<int>(transform->position.y) - (isFixed ? 0 : Game::camera.y);
		targetRectangle.w = transform->width * transform->scale;
		targetRectangle.h = transform->height * transform->scale;
	}

	void Render() override
	{
		TextureManager::DrawTexture(texture, sourceRectangle, targetRectangle, spriteFlip);
	}
};

