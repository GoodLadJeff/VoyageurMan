#include <vector>
#include <algorithm>
#include <iostream>
#include "City.h"
#include "Road.h"
#include "Traveler.h"

using namespace std;

int main()
{
    const int CITY_NUMBER = 5;
    const int MAX = 1000000;

    Road road0 = Road(0);
    Road road1 = Road(1);
    Road road2 = Road(2);
    Road road3 = Road(3);
    Road roadMax = Road(MAX);

    vector<Road*> cityGraphA = { &road0, &road2, &road2, &roadMax, &roadMax };
    vector<Road*> cityGraphB = { &road2, &road0, &road3, &road3, &road1 };
    vector<Road*> cityGraphC = { &road2, &road3, &road0, &road1, &road3 };
    vector<Road*> cityGraphD = { &roadMax, &road3, &road1, &road0, &road3 };
    vector<Road*> cityGraphE = { &roadMax, &road1, &road3, &road3, &road0 };

    const char* a = "A";
    City cityA = City("A", 0, cityGraphA);
    City cityB = City("B", 1, cityGraphB);
    City cityC = City("C", 2, cityGraphC);
    City cityD = City("D", 3, cityGraphD);
    City cityE = City("E", 4, cityGraphE);
    
    vector<City*> allCities = { &cityA, &cityB, &cityC, &cityD, &cityE };

    Traveler player = Traveler(allCities);
    player.TravelThroughCities(&cityD);

    return 0;
}