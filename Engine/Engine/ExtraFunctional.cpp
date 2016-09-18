#include "ExtraFunctional.h"


namespace ext
{


	double				DegreeToRadian(double degree)
	{
		return degree / ext::D_TO_R_RATIO;
	}

	double				RadianToDegree(double radian)
	{
		return radian * ext::D_TO_R_RATIO;
	}

	float				GetMagnitude(glm::vec2 vector)
	{
		return glm::sqrt(glm::pow(vector.x, 2) + glm::pow(vector.y, 2));
	}

	glm::vec2			GetUnitVector(double degrees)
	{
		float radians = DegreeToRadian(degrees);

		return glm::vec2(glm::sin(radians), glm::cos(radians));
	}

	glm::vec2			GetUnitVector(glm::vec2 vector)
	{
		return (vector / GetMagnitude(vector));
	}

	float				GetAngle(glm::vec2 vector)
	{
		return abs(RadianToDegree(atan2(vector.x, vector.y)));
	}

	glm::vec2			CircleThing(glm::vec2 startingPoint, glm::vec2 anchorPoint, float rotationInDegrees)
	{
		glm::vec2 relativeStartingPoint = startingPoint - anchorPoint;

		float startingAngle = GetAngle(relativeStartingPoint);
		glm::vec2 relativeEndPoint = (GetUnitVector(rotationInDegrees - startingAngle) * GetMagnitude(relativeStartingPoint));
		return (anchorPoint + relativeEndPoint);
	}

	void				ShoutGlmVector(glm::vec2 vec)
	{
		std::cout << "X: " << vec.x
			<< "\tY: " << vec.y << std::endl;
	}
	void				ShoutGlmVector(glm::vec3 vec)
	{
		std::cout << "X: " << vec.x
			<< "\tY: " << vec.y
			<< "\tZ: " << vec.z << std::endl;
	}
	void				ShoutGlmVector(glm::vec4 vec)
	{
		std::cout << "X: " << vec.x
			<< "\tY: " << vec.y
			<< "\tZ: " << vec.z
			<< "\tW: " << vec.w << std::endl;
	}

	float				GetDistance(glm::vec2 lVec, glm::vec2 rVec)
	{
		return sqrt(pow(GetMagnitude(lVec), 2) + pow(GetMagnitude(rVec), 2));
	}

	float				RToCircumfrence(float radius)
	{
		return (radius * (PI * 2));
	}

	void				MoveTowards(glm::vec2 &movingPosition, const glm::vec2 &targetPosition, float distance)
	{
		// Already There? Guard -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if (movingPosition == targetPosition)
			return;


		// Determine the amount to move
		glm::vec2 travelVector = targetPosition - movingPosition;
		float magnitude = ext::GetMagnitude(travelVector);
		if (distance > magnitude)
			distance = magnitude;

		// Add the new vector to the moving position
		movingPosition += ext::GetUnitVector(travelVector) * distance;
	}

	strVec				ReadTxt(const std::string &fileName)
	{
		std::string		line1, line2;
		std::fstream	fileStream(fileName);
		strVec			tempText;
	
		// GUARD: File Opened? --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		if (!fileStream.is_open())
		{
			std::cout << "ReadTxt(): failed to open file: " << fileName << "!\n";
			return tempText;
		}
	
	
		// ...While we haven't reached the end of the file...
		while (!fileStream.eof())
		{
			// ...Read the next 'line' from 'fileStream'
			std::getline(fileStream, line1);
			std::stringstream strStream(line1);
	
			// ...As long as there is something to read in 'strStream', add 'line2' to 'tempText'
			while (std::getline(strStream, line2))
			{
				tempText.push_back(line2);
			}
		}
	
	
		return tempText;
	}
	
	// Functions - Functional
	std::vector <int>			GetOccurences(const std::string &str, const std::string &searchFor)
	{

		std::vector<int> sVector;

		// Location of last found 'searchFor' in 'str'
		int lastFound = 0;

		// As long 'searchFor' can be found in 'str'
		while (lastFound > -1)
		{
			// Try to find 'searchFor' in 'str'
			lastFound = str.find(searchFor, lastFound);

			// If 'searchFor' was found, add to vector;
			if (lastFound > -1)
			{
				sVector.push_back(lastFound);
				// Make sure the last found occurence of 'str' in 'searchFor' isn't looked at again
				lastFound += 1;
			}
		}

		return sVector;
	}

	std::vector <std::string>	Seperate(const std::string &str, const std::string &seperator)
	{

		// To store seperated elements
		std::vector<std::string> tempVecStr;

		// If 'str' has elements...
		if (str.size() > 0)
		{
			// ...Start with 'lastSeperator'
			int lastSeperator = 0;
			while (lastSeperator > -1)
			{

				// Look if a 'seperator' can be found after the last 'lastSeperator' location...
				int endSubstr = str.find(seperator, lastSeperator);

				std::string tempString;
				//  If 'lastSeperator' was found
				if (endSubstr != -1)
				{
					// ...Add the substring to the left of the '
					tempString = str.substr(lastSeperator, endSubstr - lastSeperator);
					lastSeperator = endSubstr + seperator.length();
				}
				// ...Otherwise 'lastSeperator' was not found...
				else
				{
					tempString = str.substr(lastSeperator, -1);
					lastSeperator = endSubstr;
				}
				tempVecStr.push_back(tempString);
			}
		}

		return tempVecStr;
	}



	// Functions - Checking
	bool				StrAllLower(const std::string &str)
	{
		bool allLower = true;
		// Look at every letter inside of str...
		for (auto iter = str.begin();
			iter != str.end();
			++iter)
		{
			// ...until a character is found that is not a lowercase letter...
			if (!islower(*iter))
			{
				//... then stop the loop and indicate that str is not all lower
				allLower = false;
				break;
			}
		}
		return allLower;
	}

	bool				StrAllUpper(const std::string &str)
	{
		bool allUpper = true;
		// Look at every letter inside of str...
		for (auto iter = str.begin();
			iter != str.end();
			++iter)
		{
			// ...until a character is found that is not a lowercase letter...
			if (!isupper(*iter))
			{
				//... then stop the loop and indicate that str is not all lower
				allUpper = false;
				break;
			}
		}
		return allUpper;
	}

	bool				StrAllAlpha(const std::string &str)
	{
		bool allAlpha = true;
		// Look at every character to see if they are alphabetical
		for (auto iter = str.begin();
			iter != str.end();
			++iter)
		{
			// If a non-alphabetical character is detected, stop the loop
			if (!isalpha(*iter))
			{
				allAlpha = false;
				break;
			}
		}
		return allAlpha;
	}

	bool				StrAllDigit(const std::string &str)
	{
		bool allDigit = true;
		// Look at every character to see if they are numbers
		for (auto iter = str.begin();
			iter != str.end();
			++iter)
		{
			// If a non-alphabetical character is detected, stop the loop
			if (!isdigit(*iter))
			{
				allDigit = false;
				break;
			}
		}
		return allDigit;
	}

	bool				StrVecAllDigit(const std::vector <std::string> &strVec)
	{
		bool allDigit = true;
		// Look at every string to see if all characters are numbers
		for (auto iter = strVec.begin();
			iter != strVec.end();
			++iter)
		{
			// If there is a string that does not consist of pure digits, set 'allDigit' to false
			if (!StrAllDigit(*iter))
			{
				allDigit = false;
				break;
			}
		}

		return allDigit;
	}



	// Functions - Conversion	
	glm::vec4			StrToVec4(const std::string &str)
	{
		// Seperate the elements
		std::vector <std::string> tempVec = Seperate(str, ", ");

		glm::vec4 tempVec4(0, 0, 0, 0);

		// Ensure there are 4 elements
		if (tempVec.size() != 4)
		{
			std::cout << "ext::strToIntRect() Too many or too few elements!" << std::endl;
		}
		// ...Otherwise with exactly 4 elements...
		else
		{
			// ... Add them to 'tempVec4'
			tempVec4 = glm::vec4(std::stof(tempVec[0]),
								 std::stof(tempVec[1]),
								 std::stof(tempVec[2]),
								 std::stof(tempVec[3]));
		}
		return tempVec4;
	}

	glm::vec2			StrToVec2(const std::string &str)
	{
		// Seperate the elements
		strVec tempStrVec = Seperate(str, ", ");

		glm::vec2 tempVec2(0, 0);

		// Ensure there are 2 elements
		if (tempStrVec.size() != 2)
		{
			std::cout << "ext::strToVec2f() Too many or too few elements!" << std::endl;
		}
		// ...Otherwise with exactly 2 elements...
		else
		{
			// ... Add them to 'tempIntRect'
			tempVec2 = glm::vec2(std::stof(tempStrVec[0]),
								 std::stof(tempStrVec[1]));
		}
		return tempVec2;
	}

	std::string			Vec4ToStr(const glm::vec4 &vec)
	{
		std::string tempStr;
		std::ostringstream stream;

		// Translate the fRect into a string
		stream
			<< vec.x << ", "
			<< vec.y << ", "
			<< vec.z << ", "
			<< vec.w << '\n';
		tempStr = stream.str();

		return tempStr;
	}

	std::string			StrToLower(const std::string &str)
	{
		std::string tempStr = "";

		for (std::string::const_iterator iter = str.begin();
			iter != str.end();
			++iter)
		{
			tempStr += tolower(*iter);
		}

		return tempStr;
	}

	std::string			StrToUpper(const std::string &str)
	{
		std::string tempStr = "";

		for (std::string::const_iterator iter = str.begin();
			iter != str.end();
			++iter)
		{
			tempStr += toupper(*iter);
		}

		return tempStr;
	}



	// Functions - Math
	double				InverseATan(double oa)
	{
		return ((atan(oa) * 180) / PI);
	}

	double				InverseASin(double oh)
	{
		return ((asin(oh) * 180) / PI);
	}

	double				InverseACos(double ah)
	{
		return ((acos(ah) * 180) / PI);
	}

	glm::vec2			GetAreaOverlap(glm::vec4 &lRect, glm::vec4 &rRect)
	{

		// Intersection guard ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		/* Ensure the 2 rects are intersection */
		if (false)
			return glm::vec2(0, 0);


		// Calculate Centers of both Rects ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		/* get the center of lRect */
		glm::vec2 lCenter((lRect.x + (lRect.z / 2)),
						  (lRect.y + (lRect.w / 2)));
		// Get the center of rRect
		glm::vec2 rCenter((rRect.x + (rRect.z / 2)),
						  (rRect.y + (rRect.w / 2)));
		// Calculate relative distance
		glm::vec2 centerDistance = rCenter - lCenter;

		// Calculate Area Overlap ----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		glm::vec2 rLength(rRect.z / 2, rRect.w / 2);
		glm::vec2 lLength(lRect.z / 2, lRect.w / 2);

		rLength.x *= (centerDistance.x < 0) ? -1 : 1;
		rLength.y *= (centerDistance.y < 0) ? -1 : 1;
		lLength.x *= (centerDistance.x < 0) ? -1 : 1;
		lLength.y *= (centerDistance.y < 0) ? -1 : 1;


		return glm::vec2(-((lLength + rLength) - centerDistance));

	}

	double				GetCenterAngle(glm::vec4 &lRect, glm::vec4 &rRect)
	{
		double centerAngleReturn;

		// Calculate Centers -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		/* Calculate lRect Center */
		glm::vec2 center;
		center.x = lRect.x + (lRect.z / 2);
		center.y = lRect.y + (lRect.w / 2);

		// Calculate rRect Center
		glm::vec2 otherCenter;
		otherCenter.x = rRect.x + (rRect.z / 2);;
		otherCenter.y = rRect.y + (rRect.w / 2);

		// Calculate relative distance of the 2 centers
		glm::vec2 relativeCenter = center - otherCenter;

		// Calculate angle -----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		/* ...Get the angle at which Rect's center stands to OtherRect's center... */
		centerAngleReturn = (relativeCenter.y == 0) ? 90 :
							(relativeCenter.x == 0) ? 0 :
							abs(InverseATan(relativeCenter.x / relativeCenter.y));

		return centerAngleReturn;
	}

	float				GetDistance(glm::vec2 &pointA, glm::vec2 &pointB)
	{
		glm::vec2 distance = pointA - pointB;

		return sqrt(pow(distance.x, 2) + pow(distance.y, 2));
	}

	std::string			ExePath() {
		char* path;
		_get_pgmptr(&path);
		return path;
	}
}
