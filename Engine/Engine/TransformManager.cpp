#include "TransformManager.h"

TransformManager::TransformManager():
	ComponentManager("TRANSFORM", ComponentType::TRANSFORM)
{
}

void		TransformManager::OnUpdate()
{
	// Transforms don't update
}

Component*	TransformManager::GenerateElement(strVec &instructions)
{

	TranformComponent* transform = new TranformComponent;
	for (auto instructionIter = instructions.begin();
		instructionIter != instructions.end();
		++instructionIter)
	{
		
		strVec typeValue = ext::Seperate(*instructionIter, ": ");
		if (typeValue.size() != 2)
			continue;
		std::string &type = typeValue[0];
		std::string &value = typeValue[1];

		if (type == "position")
			transform->m_position = ext::StrToVec2(value);
		else if (type == "scale")
			transform->m_scale = ext::StrToVec2(value);
		else if (type == "rotation")
			transform->m_rotation = std::stof(value);
		
	}

	return transform;
}

void		TransformManager::MovePosition(TranformComponent * transform, glm::vec2 & vector)
{
	transform->m_position += vector;
}

void		TransformManager::SetPosition(TranformComponent * transform, glm::vec2 & vector)
{
	transform->m_position = vector;
}

glm::vec2	TransformManager::GetPosition(TranformComponent * transform)
{
	return transform->m_position;
}

void		TransformManager::SetScale(TranformComponent * transform, glm::vec2 & vector)
{
	transform->m_scale = vector;
}

glm::vec2	TransformManager::GetScale(TranformComponent * transform)
{
	return transform->m_scale;
}

void		TransformManager::Rotate(TranformComponent * transform, float rotation)
{
	transform->m_rotation += rotation;
}

void		TransformManager::SetRotation(TranformComponent * transform, float rotation)
{
	transform->m_rotation = rotation;
}

float		TransformManager::GetRotation(TranformComponent * transform)
{
	return transform->m_rotation;
}

Component* TransformManager::FabricateComponent()
{
	return new TranformComponent;
}
