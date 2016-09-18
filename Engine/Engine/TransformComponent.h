#pragma once
#include "Entity.h"
#include "Component.h"
#include <glm\glm.hpp>


struct TranformComponent : Component // is struct, public inheritance applies
{
	TranformComponent();

	glm::vec2	m_position;
	glm::vec2	m_scale;
	float		m_rotation;
};
