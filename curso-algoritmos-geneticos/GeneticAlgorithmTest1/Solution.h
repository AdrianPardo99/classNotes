#pragma once

#include <vector>
#include <string>

class Solution{
public:
	Solution(int numberOfBits, int low, int high);
	Solution(int numberOfBits, int low, int high, std::vector<int> bits);
	std::string toString() const;
	double fitness() const;

	std::vector<Solution> singlePointCrossover(Solution other, double crossoverProbability) const;
	void mutate(double mutationProbability);
private:
	double bitsToDouble() const;
private:
	int mNumberOfBits, mLow, mHigh;
	std::vector<int> mBits;//chromosomes
};
