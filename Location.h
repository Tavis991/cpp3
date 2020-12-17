//
// Created by tuli on 24/11/2020.
//

#ifndef HW2_LOCATION_H
#define HW2_LOCATION_H


#include <string>
#include "Speed.h"
#include <iostream>

using namespace std;

class Location { //location is father of gridsquare
public:
    Location():x(-1) { }
    Location( double x, double y);
    Location (const Location & other) : x(other.x), y(other.y) {} // SOMEWHERE MAKE SEGMENTATRION
    Location& operator= (const Location& rhs);
    Location&  operator + (const Speed& rhs); // have i tested this ?  not working;

    bool operator == (const Location& rhs) const ;
    bool operator > (const Location& rhs);

    void operator * (double scal);
    Location&  operator - (const Location& rhs);

    double getX() const {    return x;}
    double getY() const {    return y;}
    void setX(double frX) { x = frX; }
    void setY(double frY) { y = frY; }

    friend ostream& operator <<(ostream & os, const Location& ref);
private:

   double x,y;
};

inline ostream& operator <<(ostream & os, const Location& ref)
{

    os <<  ref.x << ' ' << ref.y << endl;

    return os;
}
#endif //HW2_LOCATION_H
