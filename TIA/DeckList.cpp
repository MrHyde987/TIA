#include "DeckList.h"

void DeckList::parseUrl(const std::string& ponyHeadUrl)
{
	int listLocation = ponyHeadUrl.find('=');
	std::string recordList = ponyHeadUrl.substr(listLocation+1);

	size_t prevLocation = 0;
	size_t nextLocation = 0;
	nextLocation = recordList.find('-', prevLocation);
	while (prevLocation != std::string::npos)
	{
		std::string nextCardRecord = recordList.substr(prevLocation, nextLocation - prevLocation);

		// Another helper to parse this token
		cardsInDeck.push_back(CardRecord(nextCardRecord));

		// TODO: This logic sucks, though it does work for now
		if (nextLocation == std::string::npos)
			prevLocation = std::string::npos;
		else
			prevLocation = nextLocation+1;
		
		nextLocation = recordList.find('-', prevLocation);
	}
}

DeckList::DeckList(const std::string& ponyHeadUrl)
{
	cardsInDeck = std::vector<CardRecord>();

	parseUrl(ponyHeadUrl);
}

const CardRecord& DeckList::getCardRecord(int idx) const
{
	return cardsInDeck[idx];
}

const int DeckList::getNumCardsInDeck() const
{
	// TODO: Perhaps store this so that we're not recomputing every time?
	int numCards = 0;
	for (int i = 0; i < cardsInDeck.size(); ++i)
		numCards += cardsInDeck[i].getMultiplicity();

	return numCards;
}

const int DeckList::getNumUniqueCardsInDeck() const
{
	return cardsInDeck.size();
}