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

	virtual void	AddElement(T *tElement );
	virtual void	RemoveElement(T *tElement );
	virtual void	ChangeElementsVec(std::vector<T*>* elementsVec);
	virtual T*		GenerateElement(strVec &instructions) = 0;
	virtual void	OnUpdate() = 0;

	void			SetCurrentLevel(Level *currentLevel);

	std::vector<T*>*	m_pElements;
	bool				m_isActive;
	Level*				m_currentLevel;
	Engine*				m_pEngine;

};




// Structors
/*Constructor*/
template<typename T>
inline ManagerTemplate<T>::ManagerTemplate() :
	m_isActive(true),
	m_pElements(nullptr)
{}

/*Destructor*/
template<typename T>
inline ManagerTemplate<T>::~ManagerTemplate()
{
	if (m_pElements == nullptr)
		return;

	// Clear m_elements
	for (auto typeIter = m_pElements->begin();
		typeIter != m_pElements->end();
		++typeIter)
	{
		delete (*typeIter);
	}
	m_pElements = nullptr;
	m_currentLevel = nullptr;
	m_pEngine = nullptr;
}




/*Adds an Element of type <T> to m_elements*/
template<typename T>
inline void ManagerTemplate<T>::AddElement(T *tElement)
{
	m_pElements->push_back(tElement);
}

/*Removes an Element of type <T> to m_elements*/
template<typename T>
inline void ManagerTemplate<T>::RemoveElement(T *tElement)
{
	auto elementIter = m_pElements->begin();
	for (; elementIter != m_pElements->end();
		++elementIter)
	{
		if (*elementIter == tElement)
			break;
	}

	m_pElements->erase(elementIter);
}

/*Changes the vector the manager is operating on*/
template<typename T>
inline void ManagerTemplate<T>::ChangeElementsVec(std::vector<T*>* elementsVec)
{
	this->m_pElements = elementsVec;
}
/*Sets the level the manager will be operating on*/
template<typename T>
inline void ManagerTemplate<T>::SetCurrentLevel(Level *currentLevel)
{
	this->m_currentLevel = currentLevel;
}
