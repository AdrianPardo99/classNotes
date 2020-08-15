#include "Solution.h"
#include "Utils.h"
#include <sstream>
#include <iostream>
#include <cmath>

Solution::Solution(int numberOfBits, int low, int high):
mNumberOfBits{numberOfBits},mLow{ low },mHigh{ high }{
	mBits.reserve(numberOfBits);//avoid reallocating //optional
	for (int i = 0; i < numberOfBits; i++){
		mBits.push_back(rand() % 2); // 0 - 1
	}
}


Solution::Solution(int numberOfBits, int low,
	int high, std::vector<int> bits):mNumberOfBits{ numberOfBits },mLow{ low },
	mHigh{ high },mBits{ bits }{}


std::string Solution::toString() const{
	std::ostringstream stream;
	stream << "[";
	for (int bit : mBits){
		stream << bit << " ";
	}
	stream << "] double = " << bitsToDouble() << " fitness = " << fitness() ;
	return stream.str();
}


double Solution::bitsToDouble() const{
	double prec = precision(mLow, mHigh, mNumberOfBits);
	int dec = 0;
	for (int i = 0; i < mNumberOfBits; i++){
		dec = dec + pow(2, i) * mBits[i];
	}
	//std::cout << "btd = " << (dec * prec + mLow) << '\n';
	return dec * prec + mLow;
}

// f(x) = x + 2 * sin(x)
double Solution::fitness() const{
	double x = bitsToDouble();
	return x + 2 * sin(x);
}


std::vector<Solution> Solution::singlePointCrossover(Solution other, double crossoverProbability) const{
	bool cross = randomProbability(crossoverProbability);

	if (cross){
		int crossPoint = rand() % mNumberOfBits;

		std::vector<int> bits1;
		std::vector<int> bits2;

		std::copy(this->mBits.begin(), this->mBits.begin() + crossPoint, std::back_inserter(bits1));
		std::copy(other.mBits.begin() + crossPoint, other.mBits.end(), std::back_inserter(bits1));

		std::copy(other.mBits.begin(), other.mBits.begin() + crossPoint, std::back_inserter(bits2));
		std::copy(this->mBits.begin() + crossPoint, this->mBits.end(), std::back_inserter(bits2));

		Solution child1{ mNumberOfBits, mLow, mHigh, bits1 };
		Solution child2{ mNumberOfBits, mLow, mHigh, bits2 };
		return { child1, child2 };
	}else{
		return { *this, other };
	}
}


void Solution::mutate(double mutationProbability){
	for (int i=0; i<mNumberOfBits; i++){
		bool mutateBool = randomProbability(mutationProbability);
		if (mutateBool){
			mBits[i] = 1 - mBits[i];//flips
		}
	}
}
