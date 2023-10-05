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

bool City::IsLinkedToCity(City* cityToCheck)
{
	for (auto var : roads) 
	{
		if (cityToCheck->CheckIsRoadLinked(&var))
			return true;
	}

	return false;
}

Road* City::GetCommonRoad(City* cityA, City* cityb)
{
	if (!cityA->IsLinkedToCity(cityb))
	{
		return nullptr;
	}
	else {
		for (auto var : cityb->GetLinkedRoads())
		{
			if (cityA->CheckIsRoadLinked(&var))
				return &var;
		}
	}
}

void City::PrintLinkedRoads()
{
	for (int i = 0; i < roads.size(); i++)
		std::cout << "Road n°" << roads[i].GetId() << " " << std::endl;
}
