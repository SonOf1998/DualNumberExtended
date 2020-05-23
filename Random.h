#pragma once

#include <random>

enum class RANDOM_GENERATION
{
	INCLUSIVE,
	EXCLUSIVE
};

class Random
{
	inline static std::random_device randomDevice;
	inline static std::mt19937 generator = std::mt19937 {randomDevice()};
	inline static constexpr double exclusionEpsilon = 0.00001;

public:
	Random ()  = delete;
	~Random () = delete;

	static int		generateInt			(int lowerBound,    int upperBound,    RANDOM_GENERATION rg = RANDOM_GENERATION::INCLUSIVE);
	static double	generateDouble		(double lowerBound, double upperBound, RANDOM_GENERATION rg = RANDOM_GENERATION::INCLUSIVE);
	static float	generateFloat		(float lowerBound,  float upperBound,  RANDOM_GENERATION rg = RANDOM_GENERATION::INCLUSIVE);
};
