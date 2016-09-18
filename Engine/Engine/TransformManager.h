#pragma once
#include "ExtraFunctional.h"
#include "ComponentManager.h"

struct TransformManager : ComponentManager
{
	TransformManager();

	virtual void OnUpdate();
	virtual Component* GenerateElement(strVec &instructions) override;

	// Position 
	void		MovePosition(TranformComponent *transform, glm::vec2 &vector);
	void		SetPosition(TranformComponent *transform, glm::vec2 &vector);
	glm::vec2	GetPosition(TranformComponent *transform);

	// Scale
	void		SetScale(TranformComponent *transform, glm::vec2 &vector);
	glm::vec2	GetScale(TranformComponent *transform);

	// Rotation
	void		Rotate(TranformComponent *transform, float rotation);
	void		SetRotation(TranformComponent *transform, float rotation);
	float		GetRotation(TranformComponent *transform);


};