#pragma once
#include "Component.h"
#include "glm\glm.hpp"


struct VelocityComponent : Component
{
	// Structors
	VelocityComponent();

	// Member Values
	glm::vec2 m_velocity;
	glm::vec2 m_gravity;
	glm::vec2 m_resistance;
};

