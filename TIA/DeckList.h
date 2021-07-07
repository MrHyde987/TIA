#pragma once
#include <string>
#include <vector>

#include "CardRecord.h"

class DeckList
{
private:
	std::vector<CardRecord> cardsInDeck;

	void parseUrl(const std::string& ponyHeadUrl);

public:
	DeckList(const std::string& ponyHeadUrl);

};

