#pragma once
#include "Road.h"
#include <vector>
#include <string>

class City
{
private :
	std::vector<Road> roads;

public :
	const char* name;
	City();
	City(std::vector<Road> r);

	static Road* GetCommonRoad(City* cityA, City* cityb);

	bool CheckIsRoadLinked(Road* road);
	void AddLinkedRoad(const Road* road) { roads.push_back(*road); }
	bool IsLinkedToCity(City* cityToCheck);
	std::vector<Road> GetLinkedRoads() { return (roads); }
	void PrintLinkedRoads();
};

