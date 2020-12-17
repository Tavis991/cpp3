#ifndef FOREST_H
#define FOREST_H
#include "GridSquare.h"
#include "Drone.h"
#include "List.h"
#include <cmath>
//
//Drone * glob_best;
//Location target;

class Forest
{
    public:

        Forest(Location target, int counter, List& lil, fstream& finale);
        ~Forest();
        Forest(const Forest& other);
        Forest& operator=(const Forest& other);
        int operator () (int x, int y);
        double euclid_to_gol (const Location& curr); //function calculates distance to target from location
        void fresh_glob();
        int operator() (int x, int y) const ;
        void iterate();
        Drone*  glob_best;  //only for now !!
        void simu_finish();  //this is finishing simulation

    private:


        GridSquare target;
        int counter;
        List lil;
        fstream& finale;
         int iterations;
        enum GRID{ y_min = 0, x_min = 0, y_max = 42, x_max = 72 };
        GridSquare GridArr [x_max][y_max];

};

#endif // FOREST_H
