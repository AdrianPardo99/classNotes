// GeneticAlgorithmTest1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <climits>

#include "Solution.h"
#include "GeneticAlgorithm.h"


int main(){
  std::cout << "Hi, student!\n";
  std::ifstream inFile;

  inFile.open("graph.txt");
  if (!inFile.is_open()){
      throw std::runtime_error("Input file error");
  }
  int numberOfCities;
  inFile >> numberOfCities;
  std::cout << "Reading " << numberOfCities << " cities " << '\n';
  int** adjacency = new int*[numberOfCities]; //dynamic allocation
  //initialize the matrix with huge distances
  for (int i = 0; i < numberOfCities; i++){
    //a matrix is just an array of arrays:
    adjacency[i] = new int[numberOfCities];
    for (int j = 0; j < numberOfCities; j++){
      if (i == j){
        adjacency[i][j] = 0; //the distance of a city to itself is 0
      }else{
        adjacency[i][j] = INT_MAX;
      }
    }
  }
  while (inFile.good()){
    int fromCity, toCity, distance;
    inFile >> fromCity;
    inFile >> toCity;
    inFile >> distance;
    std::cout << "From " << fromCity << " to " << toCity << " distance= " << distance << '\n';

    //-1 because cities are noted 1-5 in our file
    //but counting matries and arrays starts from 0
    adjacency[fromCity-1][toCity-1] = distance;
    adjacency[toCity-1][fromCity-1] = distance;
  }

  for (int i = 0; i < numberOfCities; i++){
    for (int j = 0; j < numberOfCities; j++){
      std::cout << adjacency[i][j] << ' ';
    }
    std::cout << '\n';
  }
  inFile.close();

  int populationSize = 10, generations = 10;
  int tournamentGroupSize = 3;
  double crossoverProbability = 0.7;//70%
  double mutationProbability = 0.01;//1%
  GeneticAlgorithm ga(populationSize,
    generations,
    tournamentGroupSize,
    crossoverProbability,
    mutationProbability);
  Solution bestSolution = ga.run(numberOfCities, adjacency);

  std::cout << "\nBest solution = " << bestSolution.toString() << '\n';

  //TODO: catch exceptions and deallocate the arrays in those cases as well
  for (int i = 0; i < numberOfCities; i++) {
    delete[] adjacency[i];
  }
  delete[] adjacency;
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
