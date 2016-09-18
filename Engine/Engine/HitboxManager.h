#pragma once
#include "ComponentManager.h"

struct HitboxManager : ComponentManager
{
	HitboxManager();

	// Size
	void		SetSize(glm::vec2 &size);
	glm::vec2	GetSize();

	// Checking
	bool		IsColliding(HitboxComponent* lBox, HitboxComponent* rBox);
	void		CreateCollisionLists();
	void		ClearCollisionLists();


	std::map<HitboxComponent*, std::vector<HitboxComponent*>> m_collisionLists;

};