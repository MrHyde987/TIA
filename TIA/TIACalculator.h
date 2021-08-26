#pragma once

#include <map>

#include "Archetype.h"
#include "StateReader.h"

// Main class for managing state and coordinating other operations
class TIACalculator
{
private:
	std::vector<Archetype> historicArchetypes;
	std::vector<Archetype> newArchetypeData;
	std::map<int, int> lScores;

	std::string historicDataLocation;
	std::string newDataLocation;

public:
	TIACalculator(const std::string historicDataLocation, const std::string newDataLocation);

	void ComputeTIA();
};

