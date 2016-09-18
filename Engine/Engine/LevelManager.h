#pragma once
#include <string>
#include "Level.h"
#include "ManagerTemplate.h"
#include "ExtraFunctional.h"





struct LevelManager : ManagerTemplate<Level>
{
	// Structors
	LevelManager();
	~LevelManager();

	
	Level*			GetLevelFromFile(const std::string &path);
	void			AddLevel();
	void			OnUpdate() override;
	void			AddEntityToLevel(Entity *entity, Level *level);
	


	bool			m_paused;
	std::string		m_levelDirectory;
	std::string		m_levelFileType;

//private:
	Level*					GenerateElement(strVec &levelFile);
	std::vector<strVec>		GetInstructionsForEntities(strVec &levelInstructions);

};
