#pragma once
#include "Road.h"
#include <vector>

class City
{
private :
	std::vector<Road> roads;

public :
	City();
	City(std::vector<Road> r);

	bool CheckIsRoadLinked(Road* road);
	void AddLinkedRoad(const Road* road) { roads.push_back(*road); }
	
	void PrintLinkedRoads();
};

