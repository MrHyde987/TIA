#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Archetype.h"
#include "Update.h"

// State will be stored in Yaml files, though with only a narrow subset
// of Yaml used, so this class does not have to implement a full Yaml parser
class DataReader
{
private:
	static std::ifstream stateFile;

	static void ProcessUpdates(std::vector<Update>& updates);
	static void ProcessArchetype(std::vector<Archetype>& archetypes);

public:
	static void ReadState(std::vector<Archetype>& archetypes, std::string file);
	static void ReadUpdateFile(std::vector<Update>& updates, std::string file);
};

