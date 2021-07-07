#include "TIAScore.h"

TIAScore::TIAScore()
{
	scores = new std::vector<double>();
}

TIAScore::~TIAScore()
{
	delete scores;
}

double TIAScore::ComputeTIA(const double timeFactor) const
{
	// TODO
	return 0.0;
}

void TIAScore::AddScore(const double newScore) 
{
	scores->push_back(newScore);
}