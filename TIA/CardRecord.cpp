#include "CardRecord.h"

#include <stdexcept>

CardRecord::CardRecord(Set set, int id, int multiplicity)
{
	this->set = set;
	this->id = id;
	this->multiplicity = multiplicity;
}

CardRecord::CardRecord(std::string ponyheadCardSegment)
{
	// ponyhead card segements have the form [SS(n)#x#]
	// The first two characters are the set id
	// There will be an 'n' if the card id is negative
	// The next 1-3 characters are the card num
	// There is always an 'x' next
	// The last number is a multiplicity (PH supports it being 1-9999)

	int xLocation = ponyheadCardSegment.find('x');

	std::string setId = ponyheadCardSegment.substr(0, 2);

	set = translateSetId(setId);

	int cardIdLength = xLocation - 2;

	if (ponyheadCardSegment[2] == 'n')
	{
		// Special case for cards with negative Id's
		id = std::stoi(ponyheadCardSegment.substr(3, cardIdLength - 1));
	}
	else
	{
		id = std::stoi(ponyheadCardSegment.substr(2, cardIdLength));
	}

	multiplicity = std::stoi(ponyheadCardSegment.substr(xLocation + 1, ponyheadCardSegment.length() - xLocation));
}

Set CardRecord::translateSetId(std::string setIdStr)
{
	if (setIdStr.compare("pr") == 0)
		return Set::PR;
	else if (setIdStr.compare("cn") == 0)
		return Set::CN;
	else if (setIdStr.compare("cg") == 0)
		return Set::CG;
	else if (setIdStr.compare("ad") == 0)
		return Set::AD;
	else if (setIdStr.compare("eo") == 0)
		return Set::EO;
	else if (setIdStr.compare("hm") == 0)
		return Set::HM;
	else if (setIdStr.compare("mt") == 0)
		return Set::MT;
	else if (setIdStr.compare("de") == 0)
		return Set::DE;
	else if (setIdStr.compare("sb") == 0)
		return Set::SB;
	else if (setIdStr.compare("ff") == 0)
		return Set::FF;
	else if (setIdStr.compare("ll") == 0)
		return Set::LL;
	else if (setIdStr.compare("nd") == 0)
		return Set::ND;
	else if (setIdStr.compare("fm") == 0)
		return Set::FM;
	else if (setIdStr.compare("rr") == 0)
		return Set::RR;
	else if (setIdStr.compare("cs") == 0)
		return Set::CS;
	else if (setIdStr.compare("st") == 0)
		return Set::ST;
	else if (setIdStr.compare("gf") == 0)
		return Set::GF;
	else
		throw std::invalid_argument(setIdStr);
}

const Set CardRecord::getSet() const
{
	return this->set;
}

const int CardRecord::getId() const
{
	return this->id;
}

const int CardRecord::getMultiplicity() const
{
	return this->multiplicity;
}