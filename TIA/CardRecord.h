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

class CardRecord
{
private:
	Set set;
	int id;
	int multiplicity;

	Set translateSetId(std::string setIdStr);

public:
	CardRecord(Set set, int id, int multiplicity);
	CardRecord(std::string ponyheadCardSegment);

	const Set getSet() const;
	const int getId() const;
	const int getMultiplicity() const;
};

