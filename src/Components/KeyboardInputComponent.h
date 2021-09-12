#pragma once
#include "../Game.h"
#include "../EntityManager.h"
#include "TransformComponent.h"
#include "SpriteComponent.h" //including so we can toggle between animations using keyboard input
#include "TranslationComponent.h" //including so we can impart velocity to our transform

class KeyboardInputComponent : public Component
{
public:
	std::string upKey;
	std::string downKey;
	std::string leftKey;
	std::string rightKey;
	std::string fireKey;
	TransformComponent* transform;
	SpriteComponent* sprite;
	TranslationComponent* translation;

	KeyboardInputComponent()
	{

	}

	KeyboardInputComponent(std::string upKey, std::string rightKey, std::string downKey, std::string leftKey, std::string fireKey)
	{
		this->upKey = GetSDLKeyStringCode(upKey);
		this->rightKey = GetSDLKeyStringCode(rightKey);
		this->downKey = GetSDLKeyStringCode(downKey);
		this->leftKey = GetSDLKeyStringCode(leftKey);
		this->fireKey = GetSDLKeyStringCode(fireKey);
	}

	std::string GetSDLKeyStringCode(std::string key)
	{
		if (key.compare("up") == 0)
		{
			return "1073741906";
		}
		if (key.compare("down") == 0)
		{
			return "1073741905";
		}
		if (key.compare("left") == 0)
		{
			return "1073741904";
		}
		if (key.compare("right") == 0)
		{
			return "1073741903";
		}
		if (key.compare("space") == 0)
		{
			return "32";
		}
		return std::to_string(static_cast<int>(key[0]));//return ascii value for any other key
	}

	void Initialize() override
	{
		transform = owner->GetComponent<TransformComponent>();
		sprite = owner->GetComponent<SpriteComponent>();
		translation = owner->GetComponent<TranslationComponent>();
	}

	void Update(float deltaTime) override
	{
		if (Game::event.type == SDL_KEYDOWN)
		{
			std::string keyCode = std::to_string(Game::event.key.keysym.sym);
			if (keyCode.compare(upKey) == 0)
			{
				translation->velocity.y = -80;
				translation->velocity.x = 0;
				sprite->PlayAnimation("UpAnimation");
			}
			if (keyCode.compare(rightKey) == 0)
			{
				translation->velocity.y = 0;
				translation->velocity.x = 80;
				sprite->PlayAnimation("RightAnimation");
			}
			if (keyCode.compare(downKey) == 0)
			{
				translation->velocity.y = 80;
				translation->velocity.x = 0;
				sprite->PlayAnimation("DownAnimation");
			}
			if (keyCode.compare(leftKey) == 0)
			{
				translation->velocity.y = 0;
				translation->velocity.x = -80;
				sprite->PlayAnimation("LeftAnimation");
			}
			if (keyCode.compare(fireKey) == 0)
			{
				//toDo Shoot projectiles when 'Fire' Key is pressed
				std::cout << "Fire Key Pressed";
			}
		}

		if (Game::event.type == SDL_KEYUP)
		{
			std::string keyCode = std::to_string(Game::event.key.keysym.sym);
			if (keyCode.compare(upKey) == 0)
			{
				translation->velocity.y = 0;
			}
			if (keyCode.compare(rightKey) == 0)
			{
				translation->velocity.x = 0;
			}
			if (keyCode.compare(downKey) == 0)
			{
				translation->velocity.y = 0;
			}
			if (keyCode.compare(leftKey) == 0)
			{
				translation->velocity.x = 0;
			}
			if (keyCode.compare(fireKey) == 0)
			{

			}
		}
	}
};