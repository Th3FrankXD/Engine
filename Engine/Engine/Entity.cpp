#include "Entity.h"

Entity::Entity():
	m_name(""),
	m_deathFlag(false)
{
	
}

Entity::Entity(std::string & name):
	m_name(name),
	m_deathFlag(false)
{
}

Entity::~Entity()

{
}
