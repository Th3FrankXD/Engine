#include "ComponentManager.h"

// Structors
ComponentManager::ComponentManager(const std::string &strHandle, ComponentType compType):
	m_strHandle(strHandle),
	m_componentType(compType)
{}


bool		ComponentManager::HasComponent(Entity *entity)
{
	if (entity == nullptr)
	{
		std::cout << "ComponentManager::HasComponent(): Entity == nullptr\n";
		return false;
	}
	return(entity->m_componentFlags & this->m_componentType);

}

void		ComponentManager::DestroyComponent(Component *component)
{
	// Ensure the pointers arent nullptr
	if (component == nullptr)
	{
		std::cout << "ComponentManager() Warning: component == nullptr!\n";
		return;
	}

	for (auto compIter = this->ECRMap.begin();
		compIter != this->ECRMap.end();
		++compIter)
	{
		if (compIter->second == component)
		{
			// Delete Component
			delete component;
			// Remove Component flag from Entity
			compIter->first->m_componentFlags = compIter->first->m_componentFlags ^ this->m_componentType;
			// Remove Component from ECRMap
			ECRMap.erase(compIter);
			break;
		}
	}
}

void		ComponentManager::DestroyComponent(Entity *entity)
{

	auto ECRIter = ECRMap.find(entity);
	if (ECRIter == ECRMap.end())
		return;


	delete ECRMap[entity];
	entity->m_componentFlags = entity->m_componentFlags ^ this->m_componentType;
	ECRMap.erase(ECRIter);
}

Component*	ComponentManager::CreateComponent(Entity * entity)
{
	if (entity == nullptr)
	{
		std::cout << "ComponentManager::CreateComponent(): entity == nullptr!\n";
		return nullptr;
	}
	if (this->HasComponent(entity))
		return ECRMap[entity];

	Component* newComponent = this->FabricateComponent();
	ECRMap[entity] = newComponent;

	return newComponent;
}
