#pragma once

#include <iostream>
#include <fstream>
#include <vector>

#include "Archetype.h"

// State will be stored in Yaml files, though with only a narrow subset
// of Yaml used, so this class does not have to implement a full Yaml parser
class StateReader
{
private:
	static std::ifstream stateFile;

	static void ProcessArchetype(std::vector<Archetype>& archetypes);

public:
	static void ReadState(std::vector<Archetype>& archetypes, std::string file);
};

