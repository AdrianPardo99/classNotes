#pragma once

#include <vector>
#include <string>

class Solution{
public:
	Solution(int numberOfCities, int **adjacency);
	Solution(int numberOfCities, int** adjacency, std::vector<int> cities);
	std::string toString() const;
	double fitness() const;

	std::vector<Solution> singlePointCrossover(Solution other, double crossoverProbability) const;
	void mutate(double mutationProbability);
private:
	int mNumberOfCities;
	int** mAdjacency;
	std::vector<int> mCities;//chromosomes
};
