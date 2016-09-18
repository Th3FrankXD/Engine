#pragma once
#include "Component.h"
#include "ManagerTemplate.h"


struct ComponentManager : ManagerTemplate<Component>
{
	ComponentManager(const std::string &strHandle);

	std::string			m_strHandle;

	void				AddElement(Component* tElement) override;
	void				RemoveElement(Component* tElement) override;
	virtual Component*	GenerateElement(strVec &componentInstructions) = 0;
	virtual void		OnUpdate() = 0;
};