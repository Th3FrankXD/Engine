#include "TransformComponent.h"

TranformComponent::TranformComponent():
	Component(ComponentType::TRANSFORM),
	m_position(0, 0),
	m_scale(1, 1),
	m_rotation(0.0f)
{
	
}
