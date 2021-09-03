#include "TIACalculator.h"

TIACalculator::TIACalculator(const std::string historicDataLocation, const std::string newDataLocation)
{
	historicArchetypes = std::vector<Archetype>();
	newArchetypeData = std::vector<Update>();
	lScores = std::map<int, int>();
	this->historicDataLocation = historicDataLocation;
	this->newDataLocation = newDataLocation;
}

void TIACalculator::ComputeTIA()
{
	// Read old TIA data
	DataReader::ReadState(historicArchetypes, historicDataLocation);

	// Read new tournament data
	DataReader::ReadUpdateFile(newArchetypeData, newDataLocation);

	// TODO: The rest of it...
}