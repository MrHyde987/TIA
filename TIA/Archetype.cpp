#include "Archetype.h"

// Initializing static member
int Archetype::keyCounter = 0;
std::unordered_map<std::string, int> Archetype::nameIndex = std::unordered_map<std::string, int>();

int Archetype::generateNewKey(std::string name)
{
	keyCounter++;
	nameIndex.insert(std::pair<std::string, int>(name, keyCounter));

	return keyCounter;
}

// Should never be used
Archetype::Archetype()
{

}

Archetype::Archetype(std::string name, std::pair<int, int> record, std::vector<float> tiaArchive, std::string associatedList)
{
	this->name = name;
	this->record = std::pair<int, int>(record);
	this->tiaArchive = std::vector<float>(tiaArchive);
	this->associatedDeckList = associatedList;

	if (nameIndex.count(name) > 0)
		this->key = nameIndex[name];
	else
		this->key = generateNewKey(name);
}

void Archetype::ReplaceList(const std::string newList)
{
	this->associatedDeckList = newList;
}

std::string const& Archetype::GetList() const
{
	return associatedDeckList;
}

std::vector<float> const& Archetype::GetTias() const
{
	return tiaArchive;
}

int Archetype::GetKey() const
{
	return key;
}
