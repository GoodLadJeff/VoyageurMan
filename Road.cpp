#include "Road.h"

Road::Road(int length)
{
	static int numberOfRoads;
	id = numberOfRoads;
	numberOfRoads++;

	this->length = length;
}
