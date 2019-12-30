
#include "Archetype.h"

// A TournamentRecord will hold information for a specific archetype at a specific
// tournament. That is to say, it will be an Archetype plus a record of wins and losses.

#pragma once
class TournamentRecord
{
private:
	Archetype archetype;
	int wins;
	int losses;

public:
	TournamentRecord(Archetype const& archetype);
	
	void AddWin();
	void AddLoss();

	// Probably useful for simulated Swiss events
	void AssignRecord(std::pair<int, int> newRecord);
};
