#include "JsonManager.h"
#include <fstream>
#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <string>
#include <map>

std::string getFile(std::string filePath)
{
	std::string txt;
	std::ifstream openFile(filePath);
	if (openFile.is_open())
	{
		while (!openFile.eof())
		{
			std::string currentChar;
			std::getline(openFile, currentChar);

			txt += currentChar;
		}
		openFile.close();
	}
	return txt;
}

void JsonManager::serializeJson(std::string filePath)
{
	std::string jsonFile = getFile(filePath);
	rapidjson::Document doc;
	doc.Parse(jsonFile.c_str());
	rapidjson::StringBuffer buffer;
	rapidjson::Writer<rapidjson::StringBuffer> writer(buffer);
	doc.Accept(writer);

	for (auto& itr : doc.GetObject())
	{
		switch (itr.value.GetType())
		{
		case 0: // Null
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		case 1: // False
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		case 2: // True
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		case 3: // Object
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		case 4: // Array
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		case 5: // String
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		case 6: // Number
			std::cout << itr.name.GetString() << itr.value.GetType() << "\n";
		}
	}
}
