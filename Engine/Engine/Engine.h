#pragma once

#include "Application.h"
#include "ComponentPack.h"
#include "ManagerPack.h"
#include <iostream>


class Engine : public NHTV::Application
{
public:
	Engine();
	~Engine();

	LevelManager				m_levelManager;
	EntityManager				m_entityManager;
	TransformManager			m_transformManager;

	ManagerTemplate<Component>* GetComponentMangerFromHandle(const std::string &handle);
	bool						IsValidHandle(const std::string &handle);

protected:
	virtual bool onCreate(int a_argc, char* a_argv[]);
	virtual void onUpdate(float a_deltaTime);
	virtual void onDraw();
	virtual void onDestroy();

	void LinkComponentManager(ComponentManager* pManager);

	std::map<std::string, ManagerTemplate<Component>*> strCManagerRelation;


private:
	int m_iScreenWidth;
	int m_iScreenHeight;
};