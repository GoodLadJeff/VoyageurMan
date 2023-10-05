#pragma once
#include "City.h"
#include <vector>

class Traveler
{
private:
	

public:
	std::vector<City*> citiesTraversed;
	std::vector<City*> allCities;
	City* startLocation;
	City* currentCity;
	int distanceTraveled;

	Traveler(std::vector<City*> allCities, City* startLocation);
	void SetStartLocation(City* startingCity);
	void AddCitiesVisited(City* cityVisited);
	int GetDistanceTraveled() { return distanceTraveled; }
	void AddDistanceTraveled(int distanceToAdd) { distanceTraveled += distanceToAdd; }
	void ResetDistanceTraveled() { distanceTraveled = 0; }
	City* GetCurrentCityIn() { return currentCity; }
	bool HasCityBeenVisited(City* cityToCheck);
	void SelectNewDestination();
};

