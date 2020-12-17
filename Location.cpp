//
// Created by tuli on 24/11/2020.
//

#include <cstdlib>
#include <iostream>
#include "Location.h"


Location::Location(double x, double y) : x(x), y(y)
{}

bool Location::operator == (const Location& rhs) const {

 if ((this->x == rhs.x) && (this->y == rhs.y))  { return true;}

 return false;
 }


Location &Location::operator= (const Location &rhs) {
    if (this == &rhs) return *this;
    this->x = rhs.x;
    this->y = rhs.y;
    return *this;
}



 Location&  Location::operator + (const Speed& rhs) {
    x = x + rhs.getX();
    y = y + rhs.getY();

    return *this;

 }


//bool Location::operator > (const Location& rhs){
//    return pos>rhs.pos;
//}

