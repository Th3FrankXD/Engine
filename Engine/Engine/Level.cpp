#include "Level.h"

Level::Level():
	m_name("NONE")
{
}

Level::~Level()
{
	for (auto entityIter = m_entities.begin();
		entityIter != m_entities.end();
		++entityIter)
	{
		(*entityIter)->m_deathFlag = true;
	}
}
