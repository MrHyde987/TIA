#include "pch.h"

#include "../TIA/DeckList.h"

TEST(DeckListParsing, ParseNormalList) {
	DeckList test = DeckList("http://ponyhead.com/deckbuilder?v1code=ff1x1-ll49x1-nd40x1-de56x1-ll55x1-ll56x1-ff127x1-nd131x1");

	EXPECT_EQ(test.getNumUniqueCardsInDeck(), 8);
	EXPECT_EQ(test.getNumCardsInDeck(), 8);

	const CardRecord& testRecord1 = test.getCardRecord(0);

	EXPECT_EQ(testRecord1.getSet(), Set::FF);
	EXPECT_EQ(testRecord1.getId(), 1);
	EXPECT_EQ(testRecord1.getMultiplicity(), 1);

	const CardRecord& testRecord2 = test.getCardRecord(1);

	EXPECT_EQ(testRecord2.getSet(), Set::LL);
	EXPECT_EQ(testRecord2.getId(), 49);
	EXPECT_EQ(testRecord2.getMultiplicity(), 1);
}