#include "Utils.h"
#include <cstdlib>
#include <stdexcept>
#include <set>
#include <cmath>

double randomDouble(){
	return double(rand() % 1000) / 1000; //0-999 / 1000 => 0 / 0.999
}

//bool b = randomProbability(0.7) b 70% true; b 30% false
bool randomProbability(double probability){
	if(probability < 0 || probability>1){
		throw std::runtime_error("Probability should be between 0 and 1");
	}
	double r = randomDouble();
	if(r < probability){
		return true;
	}
	return false;
}

/*
 8 bits
 11001011 => double? 2 ^ 8 = 64 (0-63)
 precision(0, 4, 8)
 (4-0)/(2^numberOfBits - 1)
*/
double precision(int low, int high, int numberOfBits){
	double prec = (double)(high - low) / (double)(pow(2, numberOfBits) - 1);
	return prec;
}

//randomDistinctNumbers(7, 3)
//3 numbers 0-6
std::set<int> randomDistinctNumbers(int upperLimit, int howManyNumbers){
	std::set<int> numbers;
	while (numbers.size() < howManyNumbers){
		numbers.insert(rand() % upperLimit);
	}
	return numbers;
}
