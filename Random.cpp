#include "Random.h"

#include <assert.h> 

int Random::generateInt(int lowerBound, int upperBound, RANDOM_GENERATION rg /* inclusive */)
{
	assert(lowerBound < upperBound);
	if (rg == RANDOM_GENERATION::EXCLUSIVE)
	{
		generateInt(lowerBound + 1, upperBound - 1, RANDOM_GENERATION::INCLUSIVE);
	}

	std::uniform_int_distribution<int> uid(lowerBound, upperBound);
	return uid(generator);
}

double Random::generateDouble(double lowerBound, double upperBound, RANDOM_GENERATION rg /* inclusive */)
{
	assert(lowerBound < upperBound);
	if (rg == RANDOM_GENERATION::EXCLUSIVE)
	{
		generateDouble(lowerBound + exclusionEpsilon, upperBound - exclusionEpsilon, RANDOM_GENERATION::INCLUSIVE);
	}

	std::uniform_real_distribution<double> uid(lowerBound, upperBound);
	return uid(generator);
}

float Random::generateFloat(float lowerBound, float upperBound, RANDOM_GENERATION rg /* inclusive */)
{
	assert(lowerBound < upperBound);
	if (rg == RANDOM_GENERATION::EXCLUSIVE)
	{
		generateDouble(lowerBound + static_cast<float>(exclusionEpsilon), upperBound - static_cast<float>(exclusionEpsilon), RANDOM_GENERATION::INCLUSIVE);
	}

	std::uniform_real_distribution<float> uid(lowerBound, upperBound);
	return uid(generator);
}



