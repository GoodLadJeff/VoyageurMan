#include "Traveler.h"


Traveler::Traveler(vector<City*> allCities)
{
    int size = allCities.size();
    for (int i = 0; i < size; i++)
    {
        vector<int> temp;
        citiesMap.push_back(temp);
        for (int j = 0; j < size; j++)
            citiesMap[i].push_back(allCities[i]->GetRoadVector()[j]->GetLength());
    }

    this->allCities = allCities;
    wayUsed = {};
}

void Traveler::TravelThroughCities(City* source)
{
    int minCost = 1000000;
    int currentCost = 0;
    int cityCurrentlyVisiting = source->GetID();

    vector<City*> currentWayUsed;

    vector<int> citiesOtherThanSource;
    for (int i = 0; i < allCities.size(); i++)
        if (i != source->GetID())
            citiesOtherThanSource.push_back(i);

    while (next_permutation(citiesOtherThanSource.begin(), citiesOtherThanSource.end()))
    {
        currentCost = 0;
        cityCurrentlyVisiting = source->GetID();

        for (int i = 0; i < citiesOtherThanSource.size(); i++)
        {
            currentCost += citiesMap[cityCurrentlyVisiting][citiesOtherThanSource[i]];
            cityCurrentlyVisiting = citiesOtherThanSource[i];
            currentWayUsed.push_back(allCities[cityCurrentlyVisiting]);
        }

        currentCost += citiesMap[cityCurrentlyVisiting][source->GetID()];

        if (minCost > currentCost)
        {
            minCost = currentCost;
            wayUsed = currentWayUsed;
        }

        currentWayUsed.clear();
    }
    
    std::cout << "the minimal cost is " << minCost << std::endl;
    std::cout << "starting from city " << source->GetName() <<", the way used is ";

    for (int i = 0; i < wayUsed.size(); i++)
    {
        std::cout << "city " << wayUsed[i]->GetName() << ", ";
    }

    std::cout << "and then back to city " << source->GetName() << "." << std::endl;
}
