#include "ComponentManager.h"

ComponentManager::ComponentManager(const std::string &strHandle)
{
	m_strHandle = strHandle;
}

void ComponentManager::AddElement(Component * tElement)
{
	if (m_currentLevel != nullptr &&
		tElement != nullptr)
	{
		m_currentLevel->m_components[tElement->m_componentType].push_back(tElement);
	}
}

void ComponentManager::RemoveElement(Component * tElement)
{
	// Ensure the pointers arent nullptr
	if (m_currentLevel == nullptr ||
		tElement == nullptr)
	{
		std::cout << "ComponentManager() Warning: m_currentLevel or tElement == nullptr!\n";
		return;
	}


	auto compIter = m_pElements->begin();
	for (;compIter != m_pElements->end();
		++compIter)
	{
		if (*compIter == tElement)
			break;
	}
	m_pElements->erase(compIter);
}
