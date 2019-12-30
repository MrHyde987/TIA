#include "TournamentRecord.h"

TournamentRecord::TournamentRecord(Archetype const& archetype)
{
	this->archetype = archetype;
	wins = 0;
	losses = 0;
}

void TournamentRecord::AddWin()
{
	wins++;
}

void TournamentRecord::AddLoss()
{
	losses++;
}

void TournamentRecord::AssignRecord(std::pair<int, int> newRecord)
{
	wins = newRecord.first;
	losses = newRecord.second;
}