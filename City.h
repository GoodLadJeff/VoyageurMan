#pragma once
#include "Road.h"
#include <vector>

using namespace std;

class City
{
private:
    int id;
    vector<Road*> roadVector;
    const char* name;

public:
    City(const char* setName, int setID, vector<Road*> graph);

    int GetID() { return id; }
    const char* GetName() { return name; }
    vector<Road*> GetRoadVector() { return roadVector; }
};