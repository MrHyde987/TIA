#include "Archetype.h"
#include "KeyGenerator.h"

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

	this->key = KeyGenerator::generateNewKey(name);
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
