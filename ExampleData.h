#pragma once
#include <windows.h>
#include <iostream>
#include <string>
#include <random>

std::default_random_engine RandomEngine; //Initialize the random engine for generating random numbers

float randomFloat(float min, float max) { //Generates a random number between two specified values (floating point w/ decimals)
	std::uniform_real_distribution<> FloatDistribution(min, max);
	return FloatDistribution(RandomEngine);
}

int randomInt(int min, int max) { //Generates a random number between two specified values (integer without decimals)
	std::uniform_int_distribution<> IntegerDistribution(min, max);
	return IntegerDistribution(RandomEngine);
}