#pragma once
#include "Road.h"
#include <vector>

class City
{
private :
	std::vector<Road> roads;

public :
	City(std::vector<Road> r);
	~City();

	bool CheckIsRoadLinked(Road* road);
};

