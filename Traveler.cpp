#include "Traveler.h"
#include <iostream>

Traveler::Traveler(std::vector<City*> allCities, City* startLocation)
{
	this->allCities = allCities;
	std::vector<City*> citiesTraversed{};
	SetStartLocation(startLocation);
	int distanceTraveled = 0;
}

void Traveler::SetStartLocation(City* startingCity)
{
	startLocation = startingCity;
	citiesTraversed.clear();
	citiesTraversed.push_back(startingCity);
	currentCity = startingCity;
}

void Traveler::AddCitiesVisited(City* cityVisited)
{
	citiesTraversed.push_back(cityVisited);
}

bool Traveler::HasCityBeenVisited(City* cityToCheck)
{
	for (auto var : citiesTraversed)
	{
		if (var == cityToCheck) return true;
	}

	return false;
}

void Traveler::SelectNewDestination()
{
	City* currentCity = GetCurrentCityIn();

	for (auto var : allCities)
	{
		if (currentCity->IsLinkedToCity(var) && !HasCityBeenVisited(var))
		{
			std::cout << "la current est " << currentCity->name << std::endl;
			distanceTraveled += City::GetCommonRoad(currentCity, var)->GetLength();
			citiesTraversed.push_back(var);
			currentCity = var;
			std::cout << "la current est devenue " << currentCity->name << std::endl;
			return;
		}
		else
		{
			std::cout <<  var->name << " la currentCity " << currentCity->name <<" n'est pas liee ou la ville a ete visitee" << std::endl;
		}
	}
}
