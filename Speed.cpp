#include "Speed.h"

Speed::Speed() : x(0), y(0)
{}

Speed::~Speed()
{
}

Speed::Speed(double x, double y): x(x), y(y)
{}

Speed::Speed(const Speed& other): x(other.x), y(other.y)
{
    //copy ctor
}


Speed&  Speed::operator * (double scal){
    x *= scal;
    y *= scal;

    return *this;
  }

Speed& Speed::operator + (const Speed& rhs){
    x = x + rhs.getX();
    y = y + rhs.getY();

    return *this;

}

Speed& Speed::operator=(const Speed& rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    this->x = rhs.x;
    this->y = rhs.y;//assignment operator
    return *this;
}
