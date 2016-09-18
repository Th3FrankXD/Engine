#pragma once
#include<vector>
#include<string>
#include "Component.h"

struct Entity
{
	Entity();
	Entity(std::string &name);
	~Entity();

	std::vector<Component*> m_pComponents;
	unsigned				m_componentFlags;
	bool					m_deathFlag;
	std::string				m_name;
};