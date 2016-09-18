#include "Engine.h"
#include "LevelManager.h"

LevelManager::LevelManager() :
	m_levelDirectory("/levels"),
	m_levelFileType("txt"),
	m_paused(false)
{

}

LevelManager::~LevelManager()
{
}



Level*		LevelManager::GetLevelFromFile(const std::string &levelName)
{
	// Make directory path
	//std::string path = this->m_levelDirectory + "/" + levelName + "." + m_levelFileType;
	// Get instructions from file
	strVec textInstructions = ext::ReadTxt("level1.txt");

	// GUARD ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (textInstructions.size() == 0)
	{
		std::cout << "LevelManager::GetLevelFromFile(): texInstructions Empty!\n";
		return nullptr;
	}
	

	Level *newLevel = GenerateElement(textInstructions);
	// Set levelName
	newLevel->m_name = levelName;

	// Interpret File

	return newLevel;
}

void		LevelManager::AddLevel()
{

}

Level*		LevelManager::GenerateElement(strVec &levelFile)
{
	// GUARD: nullptr --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (m_pEngine == nullptr)
		return nullptr;

	// Get instructions for entities
	std::vector<strVec>	entityInstructions = GetInstructionsForEntities(levelFile);

	// Make a new level
	Level* newLevel = new Level;
	// Give all of the instructions for the Entity to the Entity Manager
	for (auto entityInstructionsIter = entityInstructions.begin();
		entityInstructionsIter != entityInstructions.end();
		++entityInstructionsIter)
	{
		// Add entity to level
		Entity* tempEntityPtr = m_pEngine->m_entityManager.GenerateElement(*entityInstructionsIter);
		this->AddEntityToLevel(tempEntityPtr, newLevel);
	}

	return newLevel;
}

void		LevelManager::OnUpdate()
{
}

void		LevelManager::AddEntityToLevel(Entity *entity, Level *level)
{
	if (entity == nullptr)
		return;

	level->m_entities.push_back(entity);

	// Add Components of entity to level
	for (auto componentIter = entity->m_pComponents.begin();
		componentIter != entity->m_pComponents.end();
		++componentIter)
	{
		level->m_components[(*componentIter)->m_componentType].push_back(*componentIter);
	}
}

std::vector<strVec> LevelManager::GetInstructionsForEntities(strVec &levelInstructions)
{
	strVec				instructions;
	std::vector<strVec>	entityInstructions;
	
	// Get the instructions for all of the Entities
	for (auto lineIter = levelInstructions.begin();
		lineIter != levelInstructions.end();
		++lineIter)
	{
		// Check for the instruction of a new entity
		bool bracketsFound = (lineIter->find('[') == 0) &&
			(lineIter->find(']') == lineIter->size() - 1);
		if (bracketsFound)
		{
			// Push back the first entity
			if (instructions.size() == 0)
			{
				instructions.push_back(*lineIter);
				continue;
			}
			entityInstructions.push_back(instructions);
			instructions.clear();
		}
		instructions.push_back(*lineIter);
	}
	entityInstructions.push_back(instructions);

	return entityInstructions;
}
