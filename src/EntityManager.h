#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include "Entity.h"
#include "Component.h"
#include<vector>

#include<iostream>

class EntityManager
{
private:
	std::vector<Entity*> entities;
public:
	void Update(float deltaTime);
	void Render();
	bool HasNoEntities();
	Entity& AddEntity(std::string entityName,LayerType layer);
	std::vector<Entity*> GetEntities() const;
	std::vector<Entity*>GetEntitiesByLayer(LayerType layer) const;
	unsigned int GetEntityCount();
	void ClearData();

	void ListAllEntities();
	void ListAllEntitiesAndTheirComponents();
	std::string CheckEntityCollisions(Entity& entity) const;
	CollisionType CheckCollisions() const;
	void DestroyInactiveEntities();
};
#endif
