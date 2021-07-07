#include "DeckList.h"

void DeckList::parseUrl(const std::string& ponyHeadUrl)
{
	int listLocation = ponyHeadUrl.find('=');
	std::string recordList = ponyHeadUrl.substr(listLocation);

	size_t prevLocation = listLocation;
	size_t nextLocation = listLocation;
	nextLocation = recordList.find('-', prevLocation);
	while (nextLocation != std::string::npos)
	{
		std::string nextCardRecord = recordList.substr(prevLocation, nextLocation - prevLocation);

		// Another helper to parse this token
		cardsInDeck.push_back(CardRecord(nextCardRecord));

		prevLocation = nextLocation;
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