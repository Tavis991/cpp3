//
// Created by tuli on 21/11/2020.
//

#include "GridSquare.h"


GridSquare::GridSquare(const Location& loc)
:drone_count(0)
{
    if (loc.getX() < 43)  {  x = int(loc.getX()); }
    else {
    x = (int(loc.getX()) - int(loc.getX())%42);
    }

      if (loc.getY() < 73)  {  y = int(loc.getY()); }
    else {
    x = (int(loc.getY()) - int(loc.getY())%72);
    }

}

 bool GridSquare::operator==(GridSquare &rhs) {
    if ((x == rhs.x) && (y == rhs.y)) return true;
    return false;
}

//ostream& operator <<(ostream & os, const GridSquare& ref)

