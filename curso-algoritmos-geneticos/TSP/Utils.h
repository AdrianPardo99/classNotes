#pragma once

#include <set>

//returns 0 - 1
double randomDouble(); 

//returns true with a probability
bool randomProbability(double probability);

double precision(int low, int high, int numberOfBits);

std::set<int> randomDistinctNumbers(int upperLimit, int howManyNumbers);
