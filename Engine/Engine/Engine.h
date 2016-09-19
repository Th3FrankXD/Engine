#pragma once

#include "Application.h"
#include "ComponentPack.h"
#include "ManagerPack.h"
#include <iostream>
#include "JsonManager.h"


class Engine : public NHTV::Application
{
	friend EntityManager;
public:
	Engine();
	~Engine();

	JsonManager					m_jsonManager;
	LevelManager				m_levelManager;
	EntityManager				m_entityManager;

	TransformManager			m_transformManager;


	ManagerTemplate<Component>* GetCMangerFromHandle(const std::string &handle);
	ManagerTemplate<Component>* GetCMangerFromType(ComponentType type);
	bool						IsValidHandle(const std::string &handle);

	
protected:
	virtual bool onCreate(int a_argc, char* a_argv[]);
	virtual void onUpdate(float a_deltaTime);
	virtual void onDraw();
	virtual void onDestroy();

	void LinkComponentManager(ComponentManager* pManager);
	std::map<std::string, ComponentManager*> strToCManagerMap;
	std::map<ComponentType, ComponentManager*> cTypeToCManagerMap;
	


private:
	int m_iScreenWidth;
	int m_iScreenHeight;
};