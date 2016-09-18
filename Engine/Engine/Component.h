#pragma once



struct Entity;

enum ComponentType
{
	NONE = 0,
	TRANSFORM =	1 << 0,
	HITBOX =	1 << 1,
	SPRITE =	1 << 2,
	VELOCITY =	1 << 3,
	ANIMATION =	1 << 4,
	SCRIPT =	1 << 5
};


struct Component
{
	// Sturctors
	Component(ComponentType type);
	virtual ~Component();

	// Component Type
	ComponentType		m_componentType;

	// Death Flag
	bool				m_deathFlag;
};