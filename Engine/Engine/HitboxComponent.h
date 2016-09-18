#pragma once
#include "Component.h"
#include <glm\glm.hpp>


enum HitboxType
{
	DAMAGE = 1 << 0,
	PLAYER = 1 << 1,
	SOLID = 1 << 2
};



struct HitboxComponent : Component
{
	HitboxComponent();

	glm::vec2 m_size;


	long unsigned m_isType;
	long unsigned m_checkForType;
};
