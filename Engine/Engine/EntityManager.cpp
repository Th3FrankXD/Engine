#include "EntityManager.h"
#include "Engine.h"



EntityManager::EntityManager()
{

}

Entity* EntityManager::CreateEntity()
{
	Entity* newEntity = new Entity;
	m_entities.push_back(newEntity);

	return newEntity;
}

Entity* EntityManager::CreateEntity(std::string &name)
{
	Entity* newEntity = new Entity(name);
	m_entities.push_back(newEntity);

	return newEntity;
}

// Currently does not destroy the components as well
void EntityManager::DestroyEntity(Entity *entity)
{
	// GUARD: nullptr ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (entity == nullptr)
		return;

	auto entityIter = this->m_entities.begin();
	for (;entityIter != this->m_entities.end();
		++entityIter)
	{
		if ((*entityIter) == entity)
		{
			for (auto compManagerIter = m_pEngine->strCManagerRelation.begin();
				compManagerIter != m_pEngine->strCManagerRelation.end();
				++compManagerIter)
			{
				(*compManagerIter).second->DestroyComponent(entity);
			}

			delete (*entityIter);
			(*entityIter) = nullptr;
			this->m_entities.erase(entityIter);
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
	// Gather list of entities that need to be destroyed
	std::vector<Entity*> killMe;
	for(auto entityIter = m_entities.begin();
		entityIter != m_entities.end();
		++entityIter)
	{
		if ((*entityIter)->m_deathFlag == true)
			killMe.push_back(*entityIter);
	}

	// Destroy the entities
	for (auto killIter = killMe.begin();
		killIter != killMe.end();
		++killIter)
	{
		this->DestroyEntity(*killIter);
	}
}
