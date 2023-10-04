#include "City.h"

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
