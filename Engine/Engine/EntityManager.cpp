#include "EntityManager.h"
#include "Engine.h"



EntityManager::EntityManager()
{

}

void EntityManager::AddElement(Entity *tElement)
{
	// GUARD: nullptr ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (tElement == nullptr ||
		m_currentLevel == nullptr)
	{
		return;
	}

	m_currentLevel->m_entities.push_back(tElement);

}

void EntityManager::RemoveElement(Entity * tElement)
{
	// GUARD: nullptr ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (tElement == nullptr ||
		m_currentLevel == nullptr)
	{
		return;
	}

	// Shortcut
	auto &entityVec = m_currentLevel->m_entities;

	auto entityIter = entityVec.begin();
	for (;entityIter != entityVec.end();
		++entityIter)
	{
		if ((*entityIter) == tElement)
		{
			delete (*entityIter);
			(*entityIter) = nullptr;
			entityVec.erase(entityIter);
			return;
		}
	}
}

Entity *EntityManager::GenerateElement(strVec &entityInstructions)
{
	// GUARD: No Instructions ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (entityInstructions.size() == 0)
		return nullptr;

	// Entity to be constructed
	Entity* newEntity = nullptr;

	ComponentInstructions							instructions;
	std::map<std::string, ComponentInstructions>	componentsInstructions;

	std::string currentComponent;
	// Get the instructions for the Entity
	for (auto lineIter = entityInstructions.begin();
		lineIter != entityInstructions.end();
		++lineIter)
	{
		// Check for the instruction for the name of the Entity
		if (lineIter->find('[') == 0 &&
			lineIter->find(']') == lineIter->size() - 1)
		{
			// Create the entity and set it's name
			newEntity = new Entity;
			newEntity->m_name = lineIter->substr(1, lineIter->size() - 2);
		}// Check for the instructions of a new component
		else if (lineIter->find('<') == 0 &&
				 lineIter->find('>') == lineIter->size() - 1 &&
				 newEntity != nullptr)
		{	
			// Set the handle of the component we're giving instructions to
			std::string newComponent = lineIter->substr(1, lineIter->size() - 2);
			// Keep going if there are no instructions to push back
			if (instructions.size() == 0)
			{
				currentComponent = newComponent;
				continue;
			}

			componentsInstructions[currentComponent] = instructions;
			currentComponent = newComponent;
			instructions.clear();
		}
		else
		{
			instructions.push_back(*lineIter);
		}
	}
	componentsInstructions[currentComponent] = instructions;

	for (auto instructioniter = componentsInstructions.begin();
		instructioniter != componentsInstructions.end();
		++instructioniter)
	{
		// GUARD: Valid Handle
		if (!(m_pEngine->IsValidHandle(instructioniter->first)))
			continue;

		// Get the manager
		ManagerTemplate<Component>* manager = m_pEngine->GetComponentMangerFromHandle(instructioniter->first);
		// Give the Manager instructions and generate the Component
		newEntity->m_pComponents.push_back( manager->GenerateElement(instructioniter->second) );
	}

	return newEntity;
}

void EntityManager::OnUpdate()
{
	auto entityIter = m_pElements->begin();
	while (entityIter != m_pElements->end())
	{
		if ((*entityIter)->m_deathFlag == true)
			entityIter = m_pElements->erase(entityIter);
		else
			++entityIter;
	}
}
