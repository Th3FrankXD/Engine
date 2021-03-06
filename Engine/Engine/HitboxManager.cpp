#include "HitboxManager.h"

HitboxManager::HitboxManager():
	ComponentManager("HITBOX", ComponentType::HITBOX)
{
}

void HitboxManager::SetSize(HitboxComponent * hitbox, glm::vec2 & size)
{
	hitbox->m_size = size;
}

glm::vec2 HitboxManager::GetSize(HitboxComponent *hitbox)
{
	return hitbox->m_size;
}

bool HitboxManager::AreColliding(HitboxComponent *lBox, HitboxComponent *rBox)
{
	// Code for collission
	return false;
}

void HitboxManager::CreateCollisionLists( Level* level )
{

	std::vector<Component*> hitboxes;

	// get iter to hitbox Vec
	for (auto entityIter = level->m_entities.begin();
		entityIter != level->m_entities.end();
		++entityIter)
	{
		if ((*entityIter)->m_componentFlags & this->m_componentType)
			hitboxes.push_back(ECRMap[*entityIter]);
	}


	if (hitboxes.size() == 0)
	{
		std::cout << "HitboxManager::CreateCollisionLists(): Failed to find Hitboxes in level!\n";
		return;
	}

	// Go through each module...
	for (auto hitboxIter1 = hitboxes.begin();
		hitboxIter1 != hitboxes.end() - 1;
		++hitboxIter1)
	{
		// ...Then also go through each modules that hitboxIter1 hasn't gone through yet...
		for (auto hitboxIter2 = hitboxIter1 + 1;
			hitboxIter2 != hitboxes.end();
			++hitboxIter2)
		{
			// Cast the (Hitbox)Modules as actual HitboxModules
			HitboxComponent* hitbox = static_cast<HitboxComponent*>(*hitboxIter1);
			HitboxComponent* otherHitbox = static_cast<HitboxComponent*>(*hitboxIter2);

			// ...And if the hitboxes are colliding...
			if (AreColliding(hitbox, otherHitbox))
			{
				// ...and "hitbox" can detect "otherHitbox"...
				if (hitbox->m_checkForType & otherHitbox->m_isType)
					// ...Add "otherHitbox" to "hitbox"'s collision list...
					m_collisionLists[hitbox].push_back(otherHitbox);

				// ...Also, if "otherHitbox" can also detect "hitbox"...
				if (otherHitbox->m_checkForType & hitbox->m_isType)
					// ...Add "hitbox" to "otherHitbox"'s collision list
					m_collisionLists[otherHitbox].push_back(hitbox);
			}
		}
	}
}

void HitboxManager::ClearCollisionLists()
{
	m_collisionLists.clear();
}

Component * HitboxManager::FabricateComponent()
{
	return new HitboxComponent;
}
