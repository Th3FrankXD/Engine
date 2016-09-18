#pragma once
#include "Component.h"

struct ScriptComponent : Component
{
	ScriptComponent();

	virtual void Initialize() = 0;
	virtual void Script() = 0;
};
