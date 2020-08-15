// GeneticAlgorithmTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "Solution.h"
#include "GeneticAlgorithm.h"

int main(){
    std::cout << "Hi, student!\n";
    int populationSize = 100, generations = 10;
    int bits = 8;
    int low = 0, high = 4;
    int tournamentGroupSize = 3;
    double crossoverProbability = 0.7;//70%
    double mutationProbability = 0.01;//1%
    GeneticAlgorithm ga(populationSize,
        generations,
        tournamentGroupSize,
        crossoverProbability,
        mutationProbability);
    Solution bestSolution = ga.run(bits, low, high);

    std::cout << "\nBest solution = " << bestSolution.toString() << "\n";
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
