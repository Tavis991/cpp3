//
// Created by tuli on 21/11/2020.
//

#ifndef HW2_GRIDSQUARE_H
#define HW2_GRIDSQUARE_H
#include "Location.h"
#include <iostream>
#include <clocale>
using namespace std;

class GridSquare {
public:

    GridSquare () { }
    ~GridSquare () { }
    GridSquare (const Location& loc);
//    GridSquare (Location loc, ChessTool* player) : super(loc), player(player)
//    {}
    explicit GridSquare ( int x, int y) : x(x), y(y), drone_count(0)
    {}
    bool isEmpty() { return (!drone_count);}
    friend ostream& operator <<(ostream & os, const GridSquare& ref);
    bool operator==(GridSquare &rhs);
    GridSquare & operator%=(GridSquare &rhs);
    void operator ++ (int) { drone_count++; }
    void operator -- (int) { drone_count--; }
    void operator ++ () { drone_count++; }
    void operator -- () { drone_count--; }
    int getCount() const { return drone_count;}
    int getX() {return x;}
    int getY() {return y;}

private:
    int x;
    int y;
    int drone_count;

};

inline ostream& operator <<(ostream & os, const GridSquare& ref)
{

    os << ref.x << ' ' << ref.y << endl;

    return os;
}
#endif //HW2_GRIDSQUARE_H
