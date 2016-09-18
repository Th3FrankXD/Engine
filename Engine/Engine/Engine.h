#pragma once

#include "Application.h"
#include "ComponentPack.h"
#include "ManagerPack.h"
#include <iostream>
#include "JsonManager.h"


class Engine : public NHTV::Application
{
public:
	Engine();
	~Engine();

	JsonManager					m_jsonManager;
	LevelManager				m_levelManager;
	EntityManager				m_entityManager;
	TransformManager			m_transformManager;

	ManagerTemplate<Component>* GetComponentMangerFromHandle(const std::string &handle);
	bool						IsValidHandle(const std::string &handle);

	std::map<std::string, ComponentManager*> strCManagerRelation;
protected:
	virtual bool onCreate(int a_argc, char* a_argv[]);
	virtual void onUpdate(float a_deltaTime);
	virtual void onDraw();
	virtual void onDestroy();

	void LinkComponentManager(ComponentManager* pManager);

	


private:
	int m_iScreenWidth;
	int m_iScreenHeight;
};