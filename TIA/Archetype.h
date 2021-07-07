
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
	std::vector<std::string> associatedLists;
	double                   lScore;
	int                      key;

public:
	Archetype(std::string firstList, int key);
	
	void AddList(const std::string newList);
	std::vector<std::string> const& GetLists() const;

	void AssignL(const double newL);

	int GetKey() const;
};

