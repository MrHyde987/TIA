#include "Archetype.h"

Archetype::Archetype(std::string firstList, int key)
{
	associatedLists = std::vector<std::string>();
	associatedLists.push_back(firstList);
	lScore = 1.0;
	this->key = key;
}

void Archetype::AddList(const std::string newList)
{
	associatedLists.push_back(newList);
}

std::vector<std::string> const& Archetype::GetLists() const
{
	return associatedLists;
}

void Archetype::AssignL(const double newL)
{
	lScore = newL;
}

int Archetype::GetKey() const
{
	return key;
}
