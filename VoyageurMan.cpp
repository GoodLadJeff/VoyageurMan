#include <iostream>
#include <vector>

#include "City.h"
#include "Road.h"

int main()
{
    //il commence à D

    std::cout << "Hello VoyageurMan!\n";

    int currentCourse = 0;

    Road road1 = Road(2);
    Road road2 = Road(2);

    Road road3 = Road(3);
    Road road4 = Road(3);
    Road road5 = Road(3);
    Road road6 = Road(3);

    Road road7 = Road(3);
    Road road8 = Road(3);

    City cityA = City();
    City cityB = City();                                                                                                       
    City cityC = City();
    City cityD = City();
    City cityE = City();

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



}