
#include <vector>

#pragma once
class TIAScore
{
private:
	std::vector<double>* scores;

public:
	TIAScore();

	double ComputeTIA(const double timeFactor) const;

	void AddScore(const double newScore);
};

