#pragma once
#include "../EntityManager.h";
#include "../Game.h";
#include <glm/glm.hpp>
#include "TransformComponent.h"
#include "TranslationComponent.h";

class ProjectileEmitterComponent : public Component
{
private:
	TransformComponent* transform;
	TranslationComponent* translatation;
	glm::vec2 origin;
	int speed;
	int range;
	float angleRad;
	bool isLooping;

public:
	ProjectileEmitterComponent(int speed, int angleDeg, int range, bool isLooping)
	{
		this->speed = speed;
		this->range = range;
		this->isLooping = isLooping;
		this->angleRad = glm::radians(static_cast<float>(angleDeg));
	}

	void Initialize() override
	{
		transform = owner->GetComponent<TransformComponent>();

		origin = glm::vec2(transform->position.x, transform->position.y);

		if (owner->HasComponent<TranslationComponent>())
		{
			translatation = owner->GetComponent<TranslationComponent>();
			translatation->velocity = glm::vec2(glm::cos(angleRad) * speed, glm::sin(angleRad) * speed);
		}
		
	}

	void Update(float deltaTime) override
	{
		if (glm::distance(transform->position, origin) > range)
		{
			if (isLooping)
			{
				transform->position = origin;
			}
			else
			{
				owner->Destroy();
			}
		}
	}

};