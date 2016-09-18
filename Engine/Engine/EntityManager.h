#pragma once
#include <map>
#include "Entity.h"
#include "ManagerTemplate.h"
#include "ComponentManager.h"

struct EntityManager : ManagerTemplate<Entity>
{
	EntityManager();

	Entity*		CreateEntity(std::string &name);
	Entity*		CreateEntity();

	void		DestroyEntity(Entity *entity);
	Entity*		GenerateElement(strVec &entityInstructions);
	
	
	std::vector<Entity*> m_entities;
	void OnUpdate() override;
};
