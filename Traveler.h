#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

#include "City.h"

using namespace std;

class Traveler
{
private:
    vector<vector<int>> citiesMap;
    vector<City*> allCities;
    vector<City*> wayUsed;

public:
    Traveler(vector<City*> allCities);
    void TravelThroughCities(City* source);

    vector<vector<int>> GetCitiesMap() { return citiesMap; }
};