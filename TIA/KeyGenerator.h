#pragma once

#include <unordered_map>

class KeyGenerator
{
private:
	static int keyCounter;
	static std::unordered_map<std::string, int> nameIndex;

public:
	static int generateNewKey(std::string const& name);
};

