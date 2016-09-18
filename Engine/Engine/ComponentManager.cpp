#include "ComponentManager.h"

ComponentManager::ComponentManager(const std::string &strHandle, ComponentType compType):
	m_strHandle(strHandle),
	m_componentType(compType)
{}

void ComponentManager::SetComponent(Entity *entity, Component *component)
{
	if (entity == nullptr ||
		component == nullptr)
	{
		std::cout << "ComponentManager::SetComponent(): entity or Component\n";
		return;
	}
	
	// If there already is a component, remove it

	if (ECRMap[entity] != false)
		delete ECRMap[entity];

	ECRMap[entity] = component;
	// Add component type to Entity's component flags if not already added
	entity->m_componentFlags = entity->m_componentFlags | this->m_componentType;

}

void ComponentManager::DestroyComponent(Component *component)
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

void ComponentManager::DestroyComponent(Entity *entity)
{

	auto ECRIter = ECRMap.find(entity);
	if (ECRIter == ECRMap.end())
		return;


	delete ECRMap[entity];
	entity->m_componentFlags = entity->m_componentFlags ^ this->m_componentType;
	ECRMap.erase(ECRIter);
}
