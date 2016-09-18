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
	strVec strvec;
	strvec.push_back("[Player]");
	strvec.push_back("<TRANSFORM>");
	strvec.push_back("position: 0, 0");


	m_levelManager.SetCurrentLevel( this->m_levelManager.GenerateElement(strvec));
	

	if (m_levelManager.m_currentLevel == nullptr)
		std::cout << "m_levelManager == nullptr" << std::endl;
	std::cout << "Entities: " << m_levelManager.m_currentLevel->m_entities.size() << std::endl;
	std::cout << "Components: " << m_levelManager.m_currentLevel->m_components.size() << std::endl;

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
