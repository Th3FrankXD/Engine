#pragma once
#include "Component.h"
#include "ManagerTemplate.h"


struct ComponentManager : ManagerTemplate<Component>
{
	ComponentManager(const std::string &strHandle, ComponentType compType);

	std::string			m_strHandle;
	ComponentType		m_componentType;

	bool				HasComponent(Entity* entity);
	void				DestroyComponent(Component* tElement);
	void				DestroyComponent(Entity* entity);
	virtual Component*	CreateComponent(Entity* entity);
	virtual Component*	GenerateElement(strVec &componentInstructions) = 0;
	virtual void		OnUpdate() = 0;

	// Entity-Component Relation Map
	std::map<Entity*, Component*> ECRMap;
protected:
	virtual Component*	FabricateComponent() = 0;
};