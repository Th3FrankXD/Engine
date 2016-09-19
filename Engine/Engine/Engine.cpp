#include "Engine.h"






APPLICATION_ENTRY(Engine);



Engine::Engine()
{
	// Make sure all managers are pointing to the engine
	m_levelManager.m_pEngine = this;
	m_entityManager.m_pEngine = this;

	LinkComponentManager(&(this->m_transformManager));
}


Engine::~Engine()
{
}

ManagerTemplate<Component>* Engine::GetCMangerFromHandle(const std::string & handle)
{
	return this->strToCManagerMap[handle];
}

ManagerTemplate<Component>* Engine::GetCMangerFromType(ComponentType type)
{
	return nullptr;
}

bool Engine::IsValidHandle(const std::string & handle)
{
	return (strToCManagerMap.find(handle) != strToCManagerMap.end());
}

bool Engine::onCreate(int a_argc, char* a_argv[])
{
	m_jsonManager.serializeJson("testmap.json");


	

	setBackgroundColor(NHTV::SColour(0x00, 0x00, 0x00, 0xff));
	return true;
}

void Engine::onUpdate(float a_deltaTime)
{
}

void Engine::onDraw()
{
	clearScreen();
}

void Engine::onDestroy()
{
}

void Engine::LinkComponentManager(ComponentManager* pManager)
{
	// GUARD: nullptr ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	if (pManager == nullptr)
		return;

	// Get string handle
	this->strToCManagerMap[pManager->m_strHandle] = pManager;
	this->cTypeToCManagerMap[pManager->m_componentType] = pManager;

	// Set Manager's engine ptr to this
	pManager->m_pEngine = this;
}
