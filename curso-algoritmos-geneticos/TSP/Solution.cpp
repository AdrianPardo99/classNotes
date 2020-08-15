#include "Solution.h"
#include "Utils.h"
#include <sstream>
#include <iostream>
#include <ctime>
#include <algorithm>

Solution::Solution(int numberOfCities, int **adjacency):
	mNumberOfCities{ numberOfCities },mAdjacency{adjacency}{
	for (int i = 0; i < mNumberOfCities; i++)
		mCities.push_back(i); // 0 1 2 ... numberofcities

	std::random_shuffle(mCities.begin(), mCities.end());//randomize
}


Solution::Solution(int numberOfCities, int **adjacency, std::vector<int> cities):
	mNumberOfCities{ numberOfCities },mAdjacency{adjacency},mCities{cities}{}


std::string Solution::toString() const{
	std::ostringstream stream;
	stream << "[";
	for (int city : mCities){
		stream << city << " ";
	}
	stream << "] fitness = " << fitness() ;
	return stream.str();
}



double Solution::fitness() const{
	int totalDistance = 0;
	// cities: 0 1 3 2 4
	// 0-1 1-3 3-2 2-4 +4-0
	for (int i = 0; i < mNumberOfCities - 1; i++){
		int from = mCities[i];
		int to = mCities[i + 1];
		int distance = mAdjacency[to][from];
		totalDistance += distance;
	}
	int last = mNumberOfCities - 1;
	totalDistance += mAdjacency[0][last];
	return (-1) * totalDistance;
}


std::vector<Solution> Solution::singlePointCrossover(Solution other, double crossoverProbability) const{
	bool cross = randomProbability(crossoverProbability);

	if(cross){
		int crossPoint = rand() % mNumberOfCities;
		std::cout << "\nCrossed " << this->toString() << " x " << other.toString() << " at point " << crossPoint << '\n';

		std::vector<int> cities1;
		std::vector<int> cities2;

		std::copy(this->mCities.begin(), this->mCities.begin() + crossPoint, std::back_inserter(cities1));
		//std::copy(other.mCities.begin() + crossPoint, other.mCities.end(), std::back_inserter(cities1));

		int position = crossPoint;
		while (cities1.size() < mNumberOfCities){
			int currentCity = other.mCities[position];
			bool exists = false;
			for (int c : cities1){
				if (c == currentCity){
					exists = true;
					break;
				}
			}
			if(!exists){
				cities1.push_back(currentCity);
			}
			position++;
			if (position >= mNumberOfCities){
				position = 0;
			}
		}

		std::copy(other.mCities.begin(), other.mCities.begin() + crossPoint, std::back_inserter(cities2));
		//std::copy(this->mCities.begin() + crossPoint, this->mCities.end(), std::back_inserter(cities2));

		position = crossPoint;
		while (cities2.size() < mNumberOfCities){
			int currentCity = this->mCities[position];
			bool exists = false;
			for(int c : cities2){
				if(c == currentCity){
					exists = true;
					break;
				}
			}
			if(!exists){
				cities2.push_back(currentCity);
			}
			position++;
			if(position >= mNumberOfCities){
				position = 0;
			}
		}
		Solution child1{ mNumberOfCities, mAdjacency, cities1 };
		Solution child2{ mNumberOfCities, mAdjacency, cities2 };
		std::cout << "Children = " << child1.toString() << " & " << child2.toString() << '\n';
		return { child1, child2 };
	}
	else{
		return { *this, other };
	}
}


void Solution::mutate(double mutationProbability){
	for(int i = 0; i < mNumberOfCities; i++){
		bool mutate = randomProbability(mutationProbability);
		if(mutate){
			std::cout << "(before) Mutated solution: " << toString() << '\n';
			//swap i with another city
			int other = rand() % mNumberOfCities;
			while (other == i){
				other = rand() % mNumberOfCities;
			}
			//swap
			int aux = mCities[i];
			mCities[i] = mCities[other];
			mCities[other] = aux;
			std::cout << "Mutated solution: " << toString() << '\n';
		}
	}
}
