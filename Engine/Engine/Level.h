#pragma once
#include <map>
#include <vector>
#include "ComponentPack.h"

#ifndef LEVEL_H
#define LEVEL_H

struct Level
{
	// Structors
	Level();
	~Level();



	typedef std::map<ComponentType, std::vector<Component*>> ComponentMapVec;

	std::vector<Entity*>	m_entities;
	ComponentMapVec			m_components;
	std::string				m_name;
};

#endif // LEVEL_H