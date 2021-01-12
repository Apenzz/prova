//AUTORE: Alberto Penzo


#include "Main_station.h"
#include <iostream>
#include <string>
#include <vector>


using std::string;

Main_station::Main_station(int distance_origin, const std::string &name)
    : Station(distance_origin, name, "principale")
{
}

