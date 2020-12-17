#include "Drone.h"

Drone::Drone()
{
    //ctor
}

Drone::~Drone()
{
    //dtor
}

Drone::Drone(const Drone& other)
:loc(other.loc), sped(other.sped), per_best(other.per_best)
{
}

Drone::Drone(Location loc, Speed sped): loc(loc), sped(sped), per_best(loc)
{
//per_best =
}

Drone& Drone::operator=(const Drone& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}

//double  Drone::euclid_to_gol (const Location& curr){
//
//    double dist = pow((pow((curr.getX() - target.getX()), 2) + pow((curr.getY() - target.getY()), 2)), 0.5);
//    return dist;
//}

Location Drone::target = Location(0,0);
Drone*  Drone::glob_best = NULL;
