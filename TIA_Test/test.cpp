#include "pch.h"

#include "../TIA/DeckList.h"
#include "../TIA/StateReader.h"

TEST(DeckListParsing, ParseNormalList)
{
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

TEST(DeckListParsing, SetRecognition) 
{
	DeckList test = DeckList("http://ponyhead.com/deckbuilder?draftMode&v1code=pr1x1-cn1x1-cg191x1-ad2x1-eo1x1-hm139x1-st1x1-mt1x1-de1x1-sb1x1-ff1x1-ll1x1-nd1x1-cs1x1-rr1x1-gf7x1");

	const CardRecord& testRecord1 = test.getCardRecord(0);
	EXPECT_EQ(testRecord1.getSet(), Set::PR);

	const CardRecord& testRecord2 = test.getCardRecord(1);
	EXPECT_EQ(testRecord2.getSet(), Set::CN);

	const CardRecord& testRecord3 = test.getCardRecord(2);
	EXPECT_EQ(testRecord3.getSet(), Set::CG);

	const CardRecord& testRecord4 = test.getCardRecord(3);
	EXPECT_EQ(testRecord4.getSet(), Set::AD);

	const CardRecord& testRecord5 = test.getCardRecord(4);
	EXPECT_EQ(testRecord5.getSet(), Set::EO);

	const CardRecord& testRecord6 = test.getCardRecord(5);
	EXPECT_EQ(testRecord6.getSet(), Set::HM);

	const CardRecord& testRecord7 = test.getCardRecord(6);
	EXPECT_EQ(testRecord7.getSet(), Set::ST);

	const CardRecord& testRecord8 = test.getCardRecord(7);
	EXPECT_EQ(testRecord8.getSet(), Set::MT);

	const CardRecord& testRecord9 = test.getCardRecord(8);
	EXPECT_EQ(testRecord9.getSet(), Set::DE);

	const CardRecord& testRecord10 = test.getCardRecord(9);
	EXPECT_EQ(testRecord10.getSet(), Set::SB);

	const CardRecord& testRecord11 = test.getCardRecord(10);
	EXPECT_EQ(testRecord11.getSet(), Set::FF);

	const CardRecord& testRecord12 = test.getCardRecord(11);
	EXPECT_EQ(testRecord12.getSet(), Set::LL);

	const CardRecord& testRecord13 = test.getCardRecord(12);
	EXPECT_EQ(testRecord13.getSet(), Set::ND);

	const CardRecord& testRecord14 = test.getCardRecord(13);
	EXPECT_EQ(testRecord14.getSet(), Set::CS);

	const CardRecord& testRecord15 = test.getCardRecord(14);
	EXPECT_EQ(testRecord15.getSet(), Set::RR);

	const CardRecord& testRecord16 = test.getCardRecord(15);
	EXPECT_EQ(testRecord16.getSet(), Set::GF);
}

TEST(DeckListParsing, Multiplicity) 
{
	DeckList test = DeckList("http://ponyhead.com/deckbuilder?draftMode&v1code=eo204x1-eo205x2-eo206x3-eo207x4-eo208x5-eo209x6");

	const CardRecord& testRecord1 = test.getCardRecord(0);
	EXPECT_EQ(testRecord1.getMultiplicity(), 1);

	const CardRecord& testRecord2 = test.getCardRecord(1);
	EXPECT_EQ(testRecord2.getMultiplicity(), 2);

	const CardRecord& testRecord3 = test.getCardRecord(2);
	EXPECT_EQ(testRecord3.getMultiplicity(), 3);

	const CardRecord& testRecord4 = test.getCardRecord(3);
	EXPECT_EQ(testRecord4.getMultiplicity(), 4);

	const CardRecord& testRecord5 = test.getCardRecord(4);
	EXPECT_EQ(testRecord5.getMultiplicity(), 5);

	const CardRecord& testRecord6 = test.getCardRecord(5);
	EXPECT_EQ(testRecord6.getMultiplicity(), 6);
}

TEST(DeckListParsing, SpecialCardIds) 
{
	DeckList test = DeckList("http://ponyhead.com/deckbuilder?v1code=rrF1x1-rr1x1-cnPF3x1-cn3x1-csf1x1-adn1x1-ad1x1");

	EXPECT_EQ(test.getNumUniqueCardsInDeck(), 7);

	const CardRecord& testRecord1 = test.getCardRecord(0);
	EXPECT_EQ(testRecord1.getSet(), Set::RR);
	EXPECT_EQ(testRecord1.getSpecialId(), SpecialId::SPECIAL);

	const CardRecord& testRecord2 = test.getCardRecord(1);
	EXPECT_EQ(testRecord2.getSet(), Set::RR);
	EXPECT_EQ(testRecord2.getSpecialId(), SpecialId::NONE);

	const CardRecord& testRecord3 = test.getCardRecord(2);
	EXPECT_EQ(testRecord3.getSet(), Set::CN);
	EXPECT_EQ(testRecord3.getSpecialId(), SpecialId::PROMO_FOIL);

	const CardRecord& testRecord4 = test.getCardRecord(3);
	EXPECT_EQ(testRecord4.getSet(), Set::CN);
	EXPECT_EQ(testRecord4.getSpecialId(), SpecialId::NONE);

	const CardRecord& testRecord5 = test.getCardRecord(4);
	EXPECT_EQ(testRecord5.getSet(), Set::CS);
	EXPECT_EQ(testRecord5.getSpecialId(), SpecialId::SPECIAL);

	const CardRecord& testRecord6 = test.getCardRecord(5);
	EXPECT_EQ(testRecord6.getSet(), Set::AD);
	EXPECT_EQ(testRecord6.getSpecialId(), SpecialId::NEGATIVE);

	const CardRecord& testRecord7 = test.getCardRecord(6);
	EXPECT_EQ(testRecord7.getSet(), Set::AD);
	EXPECT_EQ(testRecord7.getSpecialId(), SpecialId::NONE);
}

TEST(YamlParsing, NormalYaml) 
{
	std::vector<Archetype> testArchetypes = std::vector<Archetype>();

	StateReader::ReadState(testArchetypes, "F:\\Documents\\Personal Code Projects\\TIA_Automation\\Test_Archive.yml");

	EXPECT_EQ(testArchetypes[0].GetList(), "<Ponyhead URL>");
	EXPECT_EQ(testArchetypes[1].GetList(), "<Ponyhead URL2>");
}