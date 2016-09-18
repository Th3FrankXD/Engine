#pragma once
#include <vector>
#include <iostream>
#include "Level.h"

// Forward Declaration
class Engine;


// typedefs
typedef std::string								EntityIdentifier;
typedef std::string								Instruction;
typedef std::vector<Instruction>				ComponentInstructions;
typedef std::vector<ComponentInstructions>		EntityInstructions;
typedef std::vector<std::string>				strVec;



template<typename T>
struct ManagerTemplate
{
	ManagerTemplate();
	virtual ~ManagerTemplate();

	virtual T*		GenerateElement(strVec &instructions) = 0;
	virtual void	OnUpdate() = 0;

	bool				m_isActive;
	Engine*				m_pEngine;

};




// Structors
/*Constructor*/
template<typename T>
inline ManagerTemplate<T>::ManagerTemplate() :
	m_isActive(true)
{}

/*Destructor*/
template<typename T>
inline ManagerTemplate<T>::~ManagerTemplate()
{
	m_pEngine = nullptr;
}


/*Sets the level the manager will be operating on*/

