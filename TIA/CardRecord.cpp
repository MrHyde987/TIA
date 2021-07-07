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
	if (setIdStr.compare("PR") == 0)
		return Set::PR;
	else if (setIdStr.compare("CN") == 0)
		return Set::CN;
	else if (setIdStr.compare("CG") == 0)
		return Set::CG;
	else if (setIdStr.compare("AD") == 0)
		return Set::AD;
	else if (setIdStr.compare("EO") == 0)
		return Set::EO;
	else if (setIdStr.compare("HM") == 0)
		return Set::HM;
	else if (setIdStr.compare("MT") == 0)
		return Set::MT;
	else if (setIdStr.compare("DE") == 0)
		return Set::DE;
	else if (setIdStr.compare("SB") == 0)
		return Set::SB;
	else if (setIdStr.compare("FF") == 0)
		return Set::FF;
	else if (setIdStr.compare("LL") == 0)
		return Set::LL;
	else if (setIdStr.compare("ND") == 0)
		return Set::ND;
	else if (setIdStr.compare("FM") == 0)
		return Set::FM;
	else if (setIdStr.compare("RR") == 0)
		return Set::RR;
	else if (setIdStr.compare("CS") == 0)
		return Set::CS;
	else if (setIdStr.compare("ST") == 0)
		return Set::ST;
	else if (setIdStr.compare("GF") == 0)
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