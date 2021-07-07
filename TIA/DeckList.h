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

	// Consider this interface (for now this function only exists to enable testing)
	const CardRecord& getCardRecord(int idx) const;

};

