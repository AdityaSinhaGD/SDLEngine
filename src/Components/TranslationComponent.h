#pragma once
#include "../EntityManager.h"
#include <glm/glm.hpp>
#include<SDL.h>
#include "../Game.h"
#include "TransformComponent.h"

class TranslationComponent:public Component
{
private:
	TransformComponent* transform;

public:
	glm::vec2 velocity;

	TranslationComponent()
	{

	}

	TranslationComponent(int velocityX, int velocitY)
	{
		velocity.x = velocityX;
		velocity.y = velocitY;
	}

	void Initialize() override
	{
		transform = owner->GetComponent<TransformComponent>();
	}

	void Update(float deltaTime) override
	{
		transform->position.x += velocity.x * deltaTime;
		transform->position.y += velocity.y * deltaTime;
	}

	void Render() override
	{

	}
	
};