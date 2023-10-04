#include "City.h"
#include <iostream>

City::City()
{
	roads = {};
}

City::City(std::vector<Road> r)
{
	roads = r;
}

bool City::CheckIsRoadLinked(Road* road)
{
	for (unsigned int i = 0; i < roads.size(); i++)
	{
		if (road->GetId() == roads[i].GetId()) return true;
	}

	return false;
}

void City::PrintLinkedRoads()
{
	for (int i = 0; i < roads.size(); i++)
		std::cout << "Road n°" << roads[i].GetId() << " " << std::endl;
}
