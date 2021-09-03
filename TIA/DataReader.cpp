
#include <stdexcept>

#include "DataReader.h"

// Initialize static member
std::ifstream DataReader::stateFile = std::ifstream();

// Example Update Yaml format:
// name: "LLTwi Orange Event Aggro"
// position: #
// wins: #
// losses: # (record of 0-0 indicates record info is not known)
// associated_list: "http://ponyhead..." The decklist associated with the archetype
// record: [W#, L#, ... ] # indicates the position of the deck this one won/lost to
///                       Empty list means the schedule info is not known
void DataReader::ProcessUpdates(std::vector<Update>& updates)
{
	std::string nextLine = "";

	// name
	std::getline(stateFile, nextLine);
	std::string name = nextLine.substr(nextLine.find(':') + 2);

	// position
	std::getline(stateFile, nextLine);
	int position = std::stoi(nextLine.substr(nextLine.find(':') + 2));

	// wins
	std::getline(stateFile, nextLine);
	int wins = std::stoi(nextLine.substr(nextLine.find(':') + 2));

	// losses
	std::getline(stateFile, nextLine);
	int losses = std::stoi(nextLine.substr(nextLine.find(':') + 2));

	// associated_list
	std::getline(stateFile, nextLine);
	std::string associatedList = nextLine.substr(nextLine.find(':') + 2);

	// record
	std::getline(stateFile, nextLine);

	std::vector<std::pair<bool, int>> records = std::vector<std::pair<bool, int>>();

	std::string recordString = nextLine.substr(nextLine.find('[') + 1);

	// records list could be empty if the data was not available
	if (recordString.compare("]") != 0)
	{
		int prevCommaPos = 0;
		int nextCommaPos = recordString.find(',');

		for (int i = 0; i < wins + losses; ++i)
		{
			std::string nextRecord = recordString.substr(prevCommaPos, nextCommaPos - prevCommaPos);

			int rootPos = nextRecord.find_first_not_of(" ");
			records.push_back(std::pair<bool, int>(nextRecord[rootPos] == 'W', std::stoi(nextRecord.substr(rootPos + 1))));

			prevCommaPos = nextCommaPos + 1;
			nextCommaPos = recordString.find(',', prevCommaPos);
		}
	}

	updates.push_back(Update(name, position, std::pair<int, int>(wins, losses), associatedList, records));
}

// Example Archetype Yaml format:
// name: "LLTwi Orange Event Aggro"
// wins: #
// losses: #
// tia_archive: [2.100, -0.500, ... etc. The ten most recent TIA #'s for the archetype)]
// associated_list: "http://ponyhead... The most recent decklist for the archetype"
void DataReader::ProcessArchetype(std::vector<Archetype>& archetypes)
{
	std::string nextLine = "";

	// name
	std::getline(stateFile, nextLine);
	std::string name = nextLine.substr(nextLine.find(':') + 2);

	// wins
	std::getline(stateFile, nextLine);
	int wins = std::stoi(nextLine.substr(nextLine.find(':') + 2));

	// losses
	std::getline(stateFile, nextLine);
	int losses = std::stoi(nextLine.substr(nextLine.find(':') + 2));

	// tia_archive
	std::getline(stateFile, nextLine);
	
	std::vector<float> tias = std::vector<float>(10);

	std::string tiaString = nextLine.substr(nextLine.find('[') + 1);
	int prevCommaPos = 0;
	int nextCommaPos = tiaString.find(',');

	for (int i = 0; i < 10; ++i)
	{
		tias[i] = std::stof(tiaString.substr(prevCommaPos, nextCommaPos - prevCommaPos));

		prevCommaPos = nextCommaPos + 1;
		nextCommaPos = tiaString.find(',', prevCommaPos);
	}

	// associated_list
	std::getline(stateFile, nextLine);
	std::string associatedList = nextLine.substr(nextLine.find(':') + 2);

	archetypes.push_back(Archetype(name, std::pair<int, int>(wins, losses), tias, associatedList));
}

void DataReader::ReadState(std::vector<Archetype>& archetypes, std::string file)
{
	if (stateFile.is_open())
	{
		throw std::exception("File is already open.");
	}

	stateFile.open(file.c_str());

	if (stateFile.is_open())
	{
		std::string nextLine = "";

		while (std::getline(stateFile, nextLine))
		{
			if (nextLine.compare("---") == 0)
			{
				// Begin next Yaml document
				ProcessArchetype(archetypes);
			}
		}
	}
	else
	{
		throw std::invalid_argument(file);
	}

	stateFile.close();
}

void DataReader::ReadUpdateFile(std::vector<Update>& updates, std::string file)
{
	if (stateFile.is_open())
	{
		throw std::exception("File is already open.");
	}

	stateFile.open(file.c_str());

	if (stateFile.is_open())
	{
		std::string nextLine = "";

		while (std::getline(stateFile, nextLine))
		{
			if (nextLine.compare("---") == 0)
			{
				// Begin next Yaml document
				ProcessUpdates(updates);
			}
		}
	}
	else
	{
		throw std::invalid_argument(file);
	}

	stateFile.close();
}
