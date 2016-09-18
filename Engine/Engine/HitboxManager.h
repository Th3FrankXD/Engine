#pragma once
#include "ComponentManager.h"

struct HitboxManager : ComponentManager
{
	HitboxManager();

	// Size
	void		SetSize(HitboxComponent* hitbox, glm::vec2 &size);
	glm::vec2	GetSize(HitboxComponent* hitbox);

	// Checking
	bool		AreColliding(HitboxComponent* lBox, HitboxComponent* rBox);
	void		CreateCollisionLists( Level* level);
	void		ClearCollisionLists();


	std::map<HitboxComponent*, std::vector<HitboxComponent*>> m_collisionLists;
};