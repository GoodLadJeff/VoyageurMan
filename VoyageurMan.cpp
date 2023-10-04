#include <iostream>
#include <vector>

#include "City.h"
#include "Road.h"

int main()
{
    //il commence à D

    std::cout << "Hello VoyageurMan!\n";

    int currentCourse = 0;

    Road road1 = Road();
    Road road2 = Road();
    std::vector<Road> r{ road1,road2 };
    City A = City(r);
                                                                                                                                        
}