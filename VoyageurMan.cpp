#include <iostream>
#include <vector>

#include "City.h"
#include "Road.h"
#include "Traveler.h"

int main()
{
    //il commence à D

    std::cout << "Hello VoyageurMan!\n";

    int currentCourse = 0;
    std::vector<City*> cities;

    Road road1 = Road(2);
    Road road2 = Road(2);
    Road road3 = Road(3);
    Road road4 = Road(3);
    Road road5 = Road(1);
    Road road6 = Road(1);
    Road road7 = Road(3);
    Road road8 = Road(3);


    City cityA = City();
    cities.push_back(&cityA);
    City cityB = City();     
    cities.push_back(&cityB);
    City cityC = City();
    cities.push_back(&cityC);
    City cityD = City();
    cities.push_back(&cityD);
    City cityE = City();
    cities.push_back(&cityE);

    cityA.name = "A";
    cityB.name = "B";
    cityC.name = "C";
    cityD.name = "D";
    cityE.name = "E";

    cityA.AddLinkedRoad(&road1);
    cityB.AddLinkedRoad(&road1);

    cityA.AddLinkedRoad(&road2);
    cityC.AddLinkedRoad(&road2);

    cityB.AddLinkedRoad(&road3);
    cityC.AddLinkedRoad(&road3);

    cityB.AddLinkedRoad(&road4);
    cityD.AddLinkedRoad(&road4);

    cityB.AddLinkedRoad(&road5);
    cityE.AddLinkedRoad(&road5);

    cityC.AddLinkedRoad(&road6);
    cityD.AddLinkedRoad(&road6);

    cityC.AddLinkedRoad(&road7);
    cityE.AddLinkedRoad(&road7);

    cityD.AddLinkedRoad(&road8);
    cityE.AddLinkedRoad(&road8);

    std::cout << "City A : " << std::endl; 
    cityA.PrintLinkedRoads();
    std::cout << "City B : " << std::endl; 
    cityB.PrintLinkedRoads();
    std::cout << "City C : " << std::endl; 
    cityC.PrintLinkedRoads();
    std::cout << "City D : " << std::endl; 
    cityD.PrintLinkedRoads();
    std::cout << "City E : " << std::endl; 
    cityE.PrintLinkedRoads();


    Traveler player = Traveler(cities, &cityD);

    for (int i = 0; i < cities.size() - 1; i++)
    {
        std::cout << player.GetDistanceTraveled() << std::endl;
        player.SelectNewDestination();
        
    }
}