#pragma once

#include <string>
#include <vector>

// Data class for new tournament data
class Update
{
private:
	std::string                                  name;
	int                                      position;
	std::pair<int, int>                        record;
	std::string                              decklist;
	int                                           key;
	
	
	// True = win, false = loss, Number corresponds to the finishing position of
	// the deck that was won/lost to
	std::vector<std::pair<bool, int>> tourneySchedule;

public:
	Update(std::string name, int position, std::pair<int, int> record, std::string decklist, std::vector<std::pair<bool, int>> tourneyScheule);

	std::vector<std::pair<bool, int>> const& GetSchedule() const;
	std::pair<int, int> const& GetRecord() const;
	const int GetKey() const;
};

