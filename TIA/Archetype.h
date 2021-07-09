
#include <string>
#include <vector>

#include "TIAScore.h"

// An Archetype holds all of the information associated with a single archetype.
// The decklists associated with it, its current L-Score, and a unique key used
// in the matching system to streamline it.

#pragma once
class Archetype
{
private:
	std::string         name;
	std::pair<int, int> record;
	std::vector<float>  tiaArchive;
	std::string         associatedDeckList;
	int                 key;

	static int keyCounter;

	static int generateNewKey();

public:
	Archetype();
	
	Archetype(std::string name, std::pair<int, int> record, std::vector<float> tiaArchive, std::string associatedList);
	
	void ReplaceList(const std::string newList);
	std::string const& GetList() const;

	int GetKey() const;
};

