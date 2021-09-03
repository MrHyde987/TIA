#include "KeyGenerator.h"

// Initializing static member
int KeyGenerator::keyCounter = 0;
std::unordered_map<std::string, int> KeyGenerator::nameIndex = std::unordered_map<std::string, int>();

int KeyGenerator::generateNewKey(std::string const& name)
{
	if (nameIndex.count(name) > 0)
	{
		return nameIndex[name];
	}
	else
	{
		keyCounter++;
		nameIndex.insert(std::pair<std::string, int>(name, keyCounter));

		return keyCounter;
	}
}