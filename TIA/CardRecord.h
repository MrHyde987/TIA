#pragma once

#include <string>

enum Set
{
	PR, // Premier
	CN, // Canterlot Nights
	CG, // The Crystal Games
	AD, // Absolute Discord
	EO, // Equestrian Odysseys
	HM, // High Magic
	MT, // Marks in Time
	DE, // Defenders of Equestria
	SB, // Seaquestria & Beyond
	FF, // Friends Forever
	LL, // Leaders & Legends
	ND, // New Dawn
	FM, // Fond Memories

	// Special/mini sets
	RR, // Rock & Rave
	CS, // Celestial Solstice
	ST, // Sands of Time
	GF  // Promotional
};

enum SpecialId
{
	NONE,      // Normal cards
	NEGATIVE,  // Secret Rares
	SPECIAL,   // Manes from RR and CS
	PROMO_FOIL // Special promo cards from earlier sets
};

class CardRecord
{
private:
	Set set;
	SpecialId idStatus;
	int id;
	int multiplicity;

	Set translateSetId(std::string setIdStr);

public:
	CardRecord(Set set, SpecialId idStatus, int id, int multiplicity);
	CardRecord(std::string ponyheadCardSegment);

	const Set getSet() const;
	const int getId() const;
	const int getMultiplicity() const;
	const SpecialId getSpecialId() const;
};

