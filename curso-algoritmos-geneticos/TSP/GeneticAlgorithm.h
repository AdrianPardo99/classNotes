#pragma once
#include "Solution.h"
class GeneticAlgorithm{
public:
	GeneticAlgorithm(int populationSize,int generations,int tournamentGroupSize,
		double crossoverProbability,double mutationProbability);
	Solution run(int numberOfCities, int **adjacency);

private:
	Solution tournamentWinner(std::vector<Solution> const& currentGeneration);
	std::vector<Solution> tournamentCrossover(std::vector<Solution> const& currentGeneration);
private:
	int mPopulationSize, mGenerations;
	int mTournamentGroupSize;
	double mMutationProbability;
	double mCrossoverProbability;
};
