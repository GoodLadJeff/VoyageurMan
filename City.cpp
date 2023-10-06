#include "City.h"

City::City(const char* setName, int setID, vector<Road*> graph)
{
    name = setName;
    id = setID;
    roadVector = graph;
}
