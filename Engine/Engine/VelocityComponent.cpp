#include "VelocityComponent.h"

VelocityComponent::VelocityComponent():
	Component(ComponentType::VELOCITY),
	m_resistance(0, 0),
	m_gravity(0, 0),
	m_velocity(0, 0)
{
}
