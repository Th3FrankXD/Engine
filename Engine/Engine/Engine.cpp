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

ManagerTemplate<Component>* Engine::GetComponentMangerFromHandle(const std::string & handle)
{
	return this->strCManagerRelation[handle];
}

bool Engine::IsValidHandle(const std::string & handle)
{
	return (strCManagerRelation.find(handle) != strCManagerRelation.end());
}

bool Engine::onCreate(int a_argc, char* a_argv[])
{
	m_jsonManager.serializeJson("testmap.json");

	strVec strvec;
	strvec.push_back("[Player]");
	strvec.push_back("<TRANSFORM>");
	strvec.push_back("position: 0, 0");


	

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
	this->strCManagerRelation[pManager->m_strHandle] = pManager;

	// Set Manager's engine ptr to this
	pManager->m_pEngine = this;
}
