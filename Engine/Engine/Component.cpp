#include "Component.h"

Component::Component(ComponentType type) :
	m_componentType(type),
	m_deathFlag(false)
{
}

Component::~Component()
{
}
