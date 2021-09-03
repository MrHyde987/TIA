#include "KeyGenerator.h"
#include "Update.h"


Update::Update(std::string name, int position, std::pair<int, int> recocord, std::string decklist, std::vector<std::pair<bool, int>> tourneySchedule)
{
	this->name = name;
	this->position = position;
	this->record = std::pair<int, int>(record);
	this->decklist = decklist;
	this->tourneySchedule = std::vector<std::pair<bool, int>>(tourneySchedule);

	this->key = KeyGenerator::generateNewKey(name);
}

std::vector<std::pair<bool, int>> const& Update::GetSchedule() const
{
	return tourneySchedule;
}

std::pair<int, int> const& Update::GetRecord() const
{
	return record;
}

const int Update::GetKey() const
{
	return key;
}