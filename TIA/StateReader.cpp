
#include <stdexcept>

#include "StateReader.h"

// Example Archetype Yaml format:
// name: "LLTwi Orange Event Aggro"
// wins: #
// losses: #
// tia_archive: [2.100, -0.500, ... etc. The ten most recent TIA #'s for the archetype)]
// associated_list: "http://ponyhead... The most recent decklist for the archetype"
void StateReader::ProcessArchetype(std::vector<Archetype>& archetypes)
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
	
	std::string tiaString = nextLine.substr(nextLine.find('[') + 1);
	int prevCommaPos = 0;
	int nextCommaPos = tiaString.find(',');
	std::vector<float> tias = std::vector<float>(10);

	for (int i = 0; i < 10; ++i)
	{
		tias[i] = std::stof(tiaString.substr(prevCommaPos, nextCommaPos - prevCommaPos));

		prevCommaPos = nextCommaPos + 1;
		nextCommaPos = tiaString.find(',', prevCommaPos);
	}

	// associated_list
	std::getline(stateFile, nextLine);
	std::string associatedList = nextLine.substr(nextLine.find(':') + 2);

	// TODO: The Archetype class needs to change to accommodate these fields
	archetypes.push_back(Archetype());
}

void StateReader::ReadState(std::vector<Archetype>& archetypes, std::string file)
{
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