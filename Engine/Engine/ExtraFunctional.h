#pragma once
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <glm\glm.hpp>

typedef std::vector<std::string> strVec;


namespace ext
{

	// Variables
	const double PI = 3.141592653589793238462643383279502884197;
	const double D_TO_R_RATIO = 57.295779513224999841;


	double		DegreeToRadian(double degree);
	double		RadianToDegree(double radian);
	float		GetMagnitude(glm::vec2 vector);

	/*Returns a unit vector in the same direction as the give angle or vector*/
	glm::vec2	GetUnitVector(double degrees);
	glm::vec2	GetUnitVector(glm::vec2 vector);
	/*Determines the clockwise angle from the Y axis 
	up		= 0/360
	right	= 90
	down	= 180
	left	= 270*/
	float		GetAngle(glm::vec2 vector);
	glm::vec2	CircleThing(glm::vec2 startingPoint, glm::vec2 anchorPoint, float rotationInDegrees);
	void		ShoutGlmVector(glm::vec2 vec);
	void		ShoutGlmVector(glm::vec3 vec);
	void		ShoutGlmVector(glm::vec4 vec);
	float		GetDistance(glm::vec2 lVec, glm::vec2 rVec);
	float		RToCircumfrence(float radius);
	void		MoveTowards(glm::vec2 &movingPosition, glm::vec2 &targetPosition, float distance);

	strVec	ReadTxt(const std::string &fileName);


	// Functions - Functional
	/*
	Function - returns a vector<int> with the the location of each occurence of 'searchFor' in 'str'
	*/
	std::vector <int>			GetOccurences(const std::string &str, const std::string &searchFor);
	/*
	Function - returns a vector of strings seperated by 'seperator' from 'str', all cases of 'seperator' are removed from the vector
	*/
	std::vector <std::string>	Seperate(const std::string &str, const std::string &seperator);


	// Functions - Checking
	/*
	Function - Returns wether or not the entire string consists of lowercase letters
	*/
	bool			StrAllLower(const std::string &str);
	/*
	Function - Returns wether or not the entire string consists of uppercase letters
	*/
	bool			StrAllUpper(const std::string &str);
	/*
	Function - Returns wether or not the entire string consists of purely letters
	*/
	bool			StrAllAlpha(const std::string &str);
	/*
	Function - Returns wether or not the entire string consists of purely digits
	*/
	bool			StrAllDigit(const std::string &str);
	/*
	Function - Returns wether or not all strings int the vector consist of purely digits
	*/
	bool			StrVecAllDigit(const std::vector <std::string> &strVec);


	// Functions - Conversion
	/*
	Function - Returns an sf::IntRect of the given str
	Parameter - '&str': the string that will be copied into a IntRect
	*/
	glm::vec4		StrToVec4(const std::string &str);
	/**/
	glm::vec2		StrToVec2(const std::string &str);
	/*
	Function - Translates the given 'FloatRect' into a 'string'
	Parameter - fRect: The 'FloatRect' that will be translated into a 'string'
	*/
	std::string		Vec4ToStr(const glm::vec4 &vec);
	/*
	Function - Returns a string of 'str' but with each character being lowercase
	*/
	std::string		StrToLower(const std::string &str);
	/*
	Function - Returns a string of 'str' but with each character being uppercase
	*/
	std::string		StrToUpper(const std::string &str);


	// Functions - Math
	/**/
	double			InverseATan(double oa);
	/**/
	double			InverseASin(double oh);
	/**/
	double			InverseACos(double ah);
	/*
	Function - Gets the overlapping area of 2 rects

	Note: The function does what it is supposed to do, but the name isn't quite suiting
	*/
	glm::vec2		GetAreaOverlap(glm::vec4 &lRect, glm::vec4 &rRect);
	/*

	*/
	double			GetCenterAngle(glm::vec4 &lRect, glm::vec4 &rRect);
	/**/
	float			GetDistance(glm::vec2 &pointA, glm::vec2 &pointB);
	
	std::string		ExePath();

}

