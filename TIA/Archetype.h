
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
	std::string         associatedDeckList;
	int                 key;

	// The current TIA scores that are contributing to the deck's current total score
	// Sum these numbers to get the archetype's current TIA score
	std::vector<float>  tiaArchive;

	static int keyCounter;

	static int generateNewKey();

public:
	Archetype();
	
	Archetype(std::string name, std::pair<int, int> record, std::vector<float> tiaArchive, std::string associatedList);
	
	void ReplaceList(const std::string newList);
	std::string const& GetList() const;
	std::vector<float> const& GetTias() const;

	int GetKey() const;
};

