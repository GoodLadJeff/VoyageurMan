#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
#define CITY_NUMBER 5
#define M 1000000

class City;
class Way;

class City
{
public:
    int id;
    vector<Way*> roadVector;

    City(int setID, Way* graph[CITY_NUMBER])
    {
        id = setID;
        roadVector = {};

        for (int i = 0; i < CITY_NUMBER; i++)
            roadVector.push_back(graph[i]);
    }
};

class Way
{
public:
    int length;

    Way(int setLength)
    {
        length = setLength;
    }
};

int tsp(vector<vector<int>> allCities, City* source)
{
    vector<int> citiesOtherThanSource;
    for (int i = 0; i < CITY_NUMBER; i++)
        if (i != source->id)
            citiesOtherThanSource.push_back(i);

    int min_cost = M;

    while (next_permutation(citiesOtherThanSource.begin(), citiesOtherThanSource.end()))
    {
        int current_cost = 0;
        int cityCurrentlyVisiting = source->id;

        for (int i = 0; i < citiesOtherThanSource.size(); i++) 
        {
            current_cost += allCities[cityCurrentlyVisiting][citiesOtherThanSource[i]];
            cityCurrentlyVisiting = citiesOtherThanSource[i];
        }

        current_cost += allCities[cityCurrentlyVisiting][source->id];
        min_cost = min(min_cost, current_cost);
    }
    return min_cost;
}

int main()
{
    Way road0 = Way(0);
    Way road1 = Way(1);
    Way road2 = Way(2);
    Way road3 = Way(3);
    Way roadMax = Way(M);
    Way* cityGraphA[CITY_NUMBER] = { &road0, &road2, &road2, &roadMax, &roadMax };
    Way* cityGraphB[CITY_NUMBER] = { &road2, &road0, &road3, &road3, &road1 };
    Way* cityGraphC[CITY_NUMBER] = { &road2, &road3, &road0, &road1, &road3 };
    Way* cityGraphD[CITY_NUMBER] = { &roadMax, &road3, &road1, &road0, &road3 };
    Way* cityGraphE[CITY_NUMBER] = { &roadMax, &road1, &road3, &road3, &road0 };


    City cityA = City(0 , cityGraphA);
    City cityB = City(1 , cityGraphB);
    City cityC = City(2, cityGraphC);
    City cityD = City(3, cityGraphD);
    City cityE = City(4, cityGraphE);
    
    City* allCities[CITY_NUMBER] = { &cityA, &cityB, &cityC, &cityD, &cityE };

    int source = 4;
    
    vector<vector<int>> final_graph;

    for (int i = 0; i < CITY_NUMBER; i++)
    {
        vector<int> temp;
        final_graph.push_back(temp);
        for (int j = 0; j < CITY_NUMBER; j++)
            final_graph[i].push_back(allCities[i]->roadVector[j]->length);
    }

    for (int i = 0; i < CITY_NUMBER; i++)
    {
        for (int j = 0; j < CITY_NUMBER; j++)
            std::cout << final_graph[i][j] << " ";
        std::cout << std::endl;
    }


    cout << tsp(final_graph, &cityD) << endl;
    return 0;
}