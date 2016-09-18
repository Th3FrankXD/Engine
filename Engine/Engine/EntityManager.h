#pragma once
#include <map>
#include "Entity.h"
#include "ManagerTemplate.h"
#include "ComponentManager.h"

struct EntityManager : ManagerTemplate<Entity>
{
	EntityManager();

	void		AddElement(Entity *tElement) override;
	void		RemoveElement(Entity *tElement) override;
	void		CreateEntity(const std::string &entityName, unsigned componentFlags);
	Entity*		GenerateElement(strVec &entityInstructions);
	
	

	void OnUpdate() override;
};
