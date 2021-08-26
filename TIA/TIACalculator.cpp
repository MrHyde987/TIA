#include "TIACalculator.h"

TIACalculator::TIACalculator(const std::string historicDataLocation, const std::string newDataLocation)
{
	historicArchetypes = std::vector<Archetype>();
	newArchetypeData = std::vector<Archetype>();
	lScores = std::map<int, int>();
	this->historicDataLocation = historicDataLocation;
	this->newDataLocation = newDataLocation;
}

void TIACalculator::ComputeTIA()
{
	// Read old TIA data
	StateReader::ReadState(historicArchetypes, false, historicDataLocation);

	// Read new tournament data
	StateReader::ReadState(newArchetypeData, true, newDataLocation);
}