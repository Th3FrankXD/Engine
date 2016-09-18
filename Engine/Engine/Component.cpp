#include "Component.h"

Component::Component(ComponentType type) :
	m_componentType(type),
	m_deathFlag(false),
	m_pEntity(nullptr)
{
}

Component::~Component()
{
	this->m_pEntity = nullptr;
}
