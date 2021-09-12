#ifndef ENTITY_H
#define ENTITY_H

#include<vector>
#include<string>
#include<map>
#include "./Constants.h"
#include "Component.h"
#include "EntityManager.h"

class EntityManager;
class Component;

class Entity
{
private:
	EntityManager& entityManager;
	bool isActive;
	std::vector<Component*> components;
	std::map<const type_info*, Component*> componentTypeMap;
public:
	std::string entityName;
	LayerType layer;
	Entity(EntityManager& entityManager);
	Entity(EntityManager& entityManager, std::string entityName, LayerType layer);
	void Update(float deltaTime);
	void Render();
	void Destroy();
	bool IsActive() const;

	template<typename T, typename... TArgs>
	T& AddComponent(TArgs&&... args)
	{
		T* newComponent(new T(std::forward<TArgs>(args)...));
		newComponent->owner = this;
		components.emplace_back(newComponent);
		componentTypeMap[&typeid(*newComponent)] = newComponent;
		newComponent->Initialize();
		return *newComponent;
	}

	template<typename T>
	T* GetComponent()
	{
		return static_cast<T*>(componentTypeMap[&typeid(T)]);
	}

	template<typename T>
	bool HasComponent() const
	{
		return componentTypeMap.count(&typeid(T));
	}
	

	std::vector<Component*> GetAllAttachedComponents();

};
#endif
